import json, re

with open(r"C:\Users\wande\Documents\ffx-editor-main\work\phyre_rtti\PHYRE_RTTI_CATALOG_20260731.json", encoding="utf-8-sig") as f:
    cat = json.load(f)

print("=== Classes SEM descriptor_addr (descriptors indiretos) - TOTAL ===")
ind = [c for c in cat["classes"].items() if not c[1]["descriptor_addrs"]]
for cname, c in sorted(ind):
    print(f"  {cname} @ {c['addr']} - {len(c['members'])} members")
print(f"TOTAL: {len(ind)}")

print("\n=== Classes com 1 member ===")
for cname, c in sorted(cat["classes"].items()):
    if len(c["members"]) == 1:
        m = c["members"][0]
        print(f"  {cname} @ {c['addr']}: member={m.get('name')} off={m.get('offset')} size={m.get('size')} type={m.get('type_expr','')[:60]}")

print("\n=== Nomes que NAO batem com padrao de registrador ===")
non_reg = []
for cname, c in sorted(cat["classes"].items()):
    if not re.search(r"Register|RegClass|ClassDescriptor|Init|_CD_|Bind", cname):
        non_reg.append((cname, c["addr"], len(c["members"])))
for n in non_reg:
    print(f"  {n[0]} @ {n[1]} ({n[2]} members)")
