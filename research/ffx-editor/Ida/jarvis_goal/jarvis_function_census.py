# RECOVERED 2026-09-18 (lane Jarvis-TOOLS-REPAIR): source restored from git history
# commit 53d82b2a, original path RuntimeTools/FFXMapViewerWeb/work/reverse/ida/scripts/<name>.
# The work/reverse/ida/scripts/ tree was never committed at its original location;
# only __pycache__/*.pyc + this history copy survived. Cited by docs/reverse/* + SESSION_HANDOFF.
import datetime
import json
import os
from collections import Counter, defaultdict

import ida_auto
import ida_bytes
import ida_funcs
import ida_lines
import ida_name
import ida_nalt
import ida_segment
import ida_ua
import idautils
import idc


DEFAULT_OUTPUT = (
    r"C:\Users\wande\Documents\ffx-editor-main"
    r"\work\reverse\ida\exports\jarvis_function_census_20260617.json"
)


def clean_text(text):
    return ida_lines.tag_remove(text or "")


def func_name(ea):
    return ida_name.get_name(ea) or ""


def is_auto_name(name):
    prefixes = (
        "sub_",
        "nullsub_",
        "j_",
        "loc_",
        "unknown_libname_",
        "SEH_",
    )
    return not name or name.startswith(prefixes)


def segment_name(ea):
    seg = ida_segment.getseg(ea)
    return ida_segment.get_segm_name(seg) if seg else ""


def function_strings(func):
    out = []
    seen = set()
    for head in idautils.Heads(func.start_ea, func.end_ea):
        for xref in idautils.DataRefsFrom(head):
            if xref in seen:
                continue
            seen.add(xref)
            try:
                text = idc.get_strlit_contents(xref, -1, idc.STRTYPE_C)
                if text:
                    try:
                        value = text.decode("utf-8", errors="replace")
                    except AttributeError:
                        value = str(text)
                    if value and len(value.strip()) >= 3:
                        out.append({"ea": hex(xref), "text": value[:160]})
            except Exception:
                pass
    return out[:12]


def call_targets(func, limit=30):
    targets = []
    seen = set()
    for head in idautils.Heads(func.start_ea, func.end_ea):
        for xref in idautils.CodeRefsFrom(head, 0):
            target_func = ida_funcs.get_func(xref)
            if not target_func or target_func.start_ea == func.start_ea:
                continue
            if target_func.start_ea in seen:
                continue
            seen.add(target_func.start_ea)
            targets.append(
                {
                    "ea": hex(target_func.start_ea),
                    "name": func_name(target_func.start_ea),
                }
            )
            if len(targets) >= limit:
                return targets
    return targets


def callers(func, limit=30):
    out = []
    seen = set()
    for xref in idautils.CodeRefsTo(func.start_ea, 0):
        caller = ida_funcs.get_func(xref)
        if not caller or caller.start_ea in seen:
            continue
        seen.add(caller.start_ea)
        out.append({"ea": hex(caller.start_ea), "name": func_name(caller.start_ea)})
        if len(out) >= limit:
            break
    return out


def first_insns(func, limit=8):
    lines = []
    for idx, head in enumerate(idautils.Heads(func.start_ea, func.end_ea)):
        if idx >= limit:
            break
        lines.append({"ea": hex(head), "text": clean_text(idc.generate_disasm_line(head, 0))})
    return lines


def build_census():
    functions = []
    stats = Counter()
    by_prefix = Counter()
    by_segment = Counter()
    auto_by_kbucket = defaultdict(list)
    auto_large = []
    named_large = []

    for ea in idautils.Functions():
        func = ida_funcs.get_func(ea)
        if not func:
            continue
        name = func_name(func.start_ea)
        size = int(func.end_ea - func.start_ea)
        seg = segment_name(func.start_ea)
        auto = is_auto_name(name)
        stats["total"] += 1
        stats["auto_named" if auto else "semantic_named"] += 1
        by_segment[seg] += 1
        prefix = name.split("_", 1)[0] if "_" in name else name[:12]
        by_prefix[prefix] += 1

        item = {
            "ea": hex(func.start_ea),
            "end_ea": hex(func.end_ea),
            "size": size,
            "name": name,
            "segment": seg,
            "auto_name": auto,
        }
        functions.append(item)

        bucket = func.start_ea & 0xFFFFF000
        if auto:
            auto_by_kbucket[bucket].append(item)
            if size >= 384:
                auto_large.append(item)
        elif size >= 768:
            named_large.append(item)

    cluster_summary = []
    for bucket, items in sorted(auto_by_kbucket.items(), key=lambda kv: (-len(kv[1]), kv[0]))[:200]:
        sizes = sorted((i["size"] for i in items), reverse=True)
        cluster_summary.append(
            {
                "bucket": hex(bucket),
                "count": len(items),
                "total_size": sum(sizes),
                "largest": sizes[:8],
                "sample": items[:12],
            }
        )

    enrich = []
    for item in sorted(auto_large, key=lambda i: (-i["size"], int(i["ea"], 16)))[:500]:
        ea = int(item["ea"], 16)
        func = ida_funcs.get_func(ea)
        if not func:
            continue
        full = dict(item)
        full["strings"] = function_strings(func)
        full["callers"] = callers(func, 20)
        full["callees"] = call_targets(func, 20)
        full["first_insns"] = first_insns(func, 8)
        enrich.append(full)

    return {
        "generated_at_utc": datetime.datetime.utcnow().isoformat() + "Z",
        "database_path": idc.get_idb_path(),
        "input_path": ida_nalt.get_input_file_path(),
        "stats": dict(stats),
        "by_segment": dict(by_segment),
        "by_prefix_top": by_prefix.most_common(200),
        "auto_cluster_summary": cluster_summary,
        "auto_large_enriched": enrich,
        "semantic_large_sample": sorted(named_large, key=lambda i: (-i["size"], int(i["ea"], 16)))[:300],
        "functions": functions,
    }


def main():
    ida_auto.auto_wait()
    output = os.environ.get("JARVIS_FUNCTION_CENSUS_OUTPUT") or DEFAULT_OUTPUT
    payload = build_census()
    os.makedirs(os.path.dirname(output), exist_ok=True)
    with open(output, "w", encoding="utf-8") as handle:
        json.dump(payload, handle, indent=2, ensure_ascii=False)
    idc.qexit(0)


if __name__ == "__main__":
    main()
