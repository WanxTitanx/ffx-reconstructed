#!/usr/bin/env python3
"""Integrated Phase-2 migrator for a batch (default s4). Handles per non-EN item:
  .axaml UI attr literal -> Strings.KEY via {x:Static}; .cs UI quoted literal -> Strings.KEY;
  .cs   log quoted literal -> direct EN swap. Interpolated tokens skipped to REVIEW.
Writes a plan JSON + (with --apply) .bak of touched files and edits source/resx/cs.
"""
import json, os, sys, re, shutil, datetime, hashlib, argparse
from collections import Counter

ROOT = r"C:\Users\wande\Documents\ffx-editor-main"
RESX   = os.path.join(ROOT, "FFXProjectEditor", "Resources", "Strings.resx")
PTRESX = os.path.join(ROOT, "FFXProjectEditor", "Resources", "Strings.pt.resx")
STRCS  = os.path.join(ROOT, "FFXProjectEditor", "Resources", "Strings.cs")
ATTRS  = ["Text","Content","Header","Watermark","ToolTip","Subtitle","Caption","Placeholder","Title"]

def esc(s):
    return s.replace("&","&amp;").replace("<","&lt;").replace(">","&gt;").replace('"',"&quot;")

def gen_key(text, used):
    slug = re.sub(r"[^a-z0-9]+","_",text.lower()).strip("_")[:42] or "lit"
    h = hashlib.sha1(text.encode("utf-8")).hexdigest()[:8]
    k = f"F2_{slug}_{h}"; i=1
    while k in used: k=f"F2_{slug}_{i}_{h}"; i+=1
    used.add(k); return k

def existing_keys():
    import xml.etree.ElementTree as ET
    ks=set()
    for p in (RESX,PTRESX):
        try: r=ET.parse(p).getroot()
        except Exception: continue
        for d in r.iter("data"):
            if d.get("name"): ks.add(d.get("name"))
    return ks

def find_attr(line, needle):
    for an in ATTRS:
        m=re.search(an+r'\s*=\s*"([^"]*)"', line)
        if m and needle in m.group(1): return m.group(1)
    return None

def find_cs(line, needle):
    for m in re.finditer(r'"([^"]*)"', line):
        if needle in m.group(1): return m.group(1)
    return None

def _suspect(en, token, line_txt=None):
    # a clearly truncated/unsafe EN: unbalanced brace, or long sentence without closing punct,
    # or token/literal that looks like a mid-concat fragment
    if en.count("{") != en.count("}"):
        return True
    if token and (token.startswith(" ") or token.endswith(" ")):
        return True  # leading/ending-space fragment of string concatenation
    if line_txt is not None:
        # string concatenation fragment: line has + adjacent to quotes (two+ quoted chunks)
        if re.search(r'"[^"]*"\s*\+', line_txt) or re.search(r'\+\s*"', line_txt):
            return True
    ENDS = ('.', ':', '!', '?', ')', ']', '"', ',', '}', ';')
    if len(en) > 34 and not en.endswith(ENDS):
        return True  # long sentence that got cut off
    return False

def build_plan(files):
    data=[]
    for fp in files: data.extend(json.load(open(fp,encoding="utf-8")))
    used=existing_keys(); plan=[]
    for it in data:
        if it.get("text")==it.get("en"): continue
        f=it["file"].replace("/",os.sep); full=os.path.join(ROOT,f)
        if not os.path.exists(full):
            plan.append({**it,"action":"REVIEW","reason":"missing-file"}); continue
        txt=it["text"]; en=it["en"]; typ=it.get("type")
        is_ax=f.lower().endswith(".axaml") and not f.lower().endswith(".cs")
        is_cs=f.lower().endswith(".cs")
        if re.search(r"\{[0-9a-zA-Z_\.\?]+\}", txt):
            plan.append({**it,"action":"REVIEW","reason":"format-braces"}); continue
        lines=open(full,encoding="utf-8").read().split("\n")
        cand=[(i,l) for i,l in enumerate(lines,1) if txt in l]
        if not cand:
            plan.append({**it,"action":"REVIEW","reason":"literal-not-found"}); continue
        ln,lt=min(cand,key=lambda c:abs(c[0]-it["line"]))
        token=find_attr(lt,txt) if is_ax else (find_cs(lt,txt) if is_cs else None)
        if token is None:
            plan.append({**it,"action":"REVIEW","reason":"token-not-resolved","line":ln}); continue
        if token != txt:
            # needle is a substring of a bigger literal (prefix/suffix) -> replacing would lose text
            plan.append({**it,"action":"REVIEW","reason":"token-not-exact","token":token,"line":ln}); continue
        if ("\n".join(lines)).count(token)!=1:
            plan.append({**it,"action":"REVIEW","reason":"not-unique","token":token,"line":ln}); continue
        if _suspect(en, token, lt):
            plan.append({**it,"action":"REVIEW","reason":"suspect-en-trunc","token":token,"line":ln}); continue
        if is_ax and typ=="ui":
            plan.append({**it,"action":"UI_AXAML","key":gen_key(token,used),"token":token,"line":ln})
        elif is_cs and typ=="ui":
            plan.append({**it,"action":"UI_CS","key":gen_key(token,used),"token":token,"line":ln})
        elif is_cs and typ=="log":
            plan.append({**it,"action":"LOG","token":token,"en":en,"line":ln})
        else:
            plan.append({**it,"action":"REVIEW","reason":f"unhandled({is_ax},{is_cs},{typ})","line":ln})
    return plan

def append_resx(path, key, val):
    with open(path,"r",encoding="utf-8",newline="") as f: text=f.read()
    if f'<data name="{key}"' in text: return False
    idx=text.rfind("</root>")
    block=f'<data name="{key}" xml:space="preserve"><value>{esc(val)}</value></data>\n'
    with open(path,"w",encoding="utf-8",newline="") as f: f.write(text[:idx]+block+text[idx:])
    return True

def append_cs_props(keys):
    if not keys: return
    props="\n".join(f"    public static string {k} => Get(nameof({k}));" for k in keys)
    with open(STRCS,"r",encoding="utf-8",newline="") as f: text=f.read()
    idx=text.rfind("}")
    if idx!=-1:
        text=text[:idx]+"\n\n"+props+"\n"+text[idx:]
    with open(STRCS,"w",encoding="utf-8",newline="") as f: f.write(text)
def main():
    ap=argparse.ArgumentParser(); ap.add_argument("--files",nargs="*"); ap.add_argument("--apply",action="store_true")
    a=ap.parse_args()
    files=a.files or [os.path.join(ROOT,"work","i18n_s4_rest_result.json")]
    plan=build_plan(files)
    print("Plan:",dict(Counter(p["action"] for p in plan)))
    for p in plan:
        if p["action"] in ("UI_AXAML","UI_CS","LOG"):
            print(f"  {p['action']:8} {p['file']}:{p['line']} | {p['token'][:40]}")
    planpath=os.path.join(ROOT,"work","i18n_fase2_plan.json")
    with open(planpath,"w",encoding="utf-8") as f: json.dump(plan,f,ensure_ascii=False,indent=1)
    print("plan ->",planpath)
    if not a.apply:
        print("(dry-run; --apply to write)"); return
    ts=datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
    keyinfo={}; src=[]
    for p in plan:
        if p["action"]=="UI_AXAML":
            keyinfo[p["key"]]=(p["en"],p["text"]); src.append((p["file"].replace("/",os.sep),p["token"],"{x:Static res:Strings."+p["key"]+"}"))
        elif p["action"]=="UI_CS":
            keyinfo[p["key"]]=(p["en"],p["text"]); src.append((p["file"].replace("/",os.sep),p["token"],"Strings."+p["key"]))
        elif p["action"]=="LOG":
            src.append((p["file"].replace("/",os.sep),p["token"],p["en"]))
    if keyinfo:
        for k,(en,pt) in keyinfo.items():
            append_resx(RESX,k,en); append_resx(PTRESX,k,pt)
        append_cs_props(list(keyinfo.keys()))
    seen=set()
    for f,tok,repl in src:
        full=os.path.join(ROOT,f)
        if full not in seen:
            bak=full+f".i18n_bak_{ts}"; shutil.copy2(full,bak); seen.add(full)
        with open(full,"r",encoding="utf-8",newline="") as fh: c=fh.read()
        c=c.replace(tok,repl,1)
        with open(full,"w",encoding="utf-8",newline="") as fh: fh.write(c)
    print(f"applied {len(src)} source edits, {len(keyinfo)} keys; backups '{ts}'")

if __name__=="__main__":
    main()
