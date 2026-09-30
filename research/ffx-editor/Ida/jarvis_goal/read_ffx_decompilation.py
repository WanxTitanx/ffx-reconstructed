# RECOVERED 2026-09-18 (lane Jarvis-TOOLS-REPAIR): source restored from git history
# commit 53d82b2a, original path RuntimeTools/FFXMapViewerWeb/work/reverse/ida/scripts/<name>.
# The work/reverse/ida/scripts/ tree was never committed at its original location;
# only __pycache__/*.pyc + this history copy survived. Cited by docs/reverse/* + SESSION_HANDOFF.
import argparse
import json
import os
import re
import sys
from collections import Counter


CALL_RE = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(")
STRING_RE = re.compile(r'"([^"\\]*(?:\\.[^"\\]*)*)"')
CALL_KEYWORDS = {
    "if",
    "for",
    "while",
    "switch",
    "return",
    "sizeof",
}
IGNORED_CALL_NAMES = {
    "void",
    "char",
    "int",
    "float",
    "double",
    "memcpy",
    "memset",
}


def load_payload(path):
    with open(path, "r", encoding="utf-8") as handle:
        return json.load(handle)


def matches(item, needle):
    if not needle:
        return True

    haystacks = [
        item.get("target", ""),
        item.get("name", ""),
        item.get("demangled_name", ""),
        item.get("ea", ""),
        item.get("pseudocode", "") or "",
    ]
    flat = "\n".join(str(value) for value in haystacks).lower()
    return needle.lower() in flat


def unique_preserve(items):
    seen = set()
    ordered = []
    for item in items:
        if not item or item in seen:
            continue
        seen.add(item)
        ordered.append(item)
    return ordered


def extract_string_literals(item):
    pseudocode = item.get("pseudocode") or ""
    literals = [match.group(1) for match in STRING_RE.finditer(pseudocode)]
    return unique_preserve(literals)


def extract_called_functions(item):
    pseudocode = item.get("pseudocode") or ""
    current_name = item.get("name") or ""
    callees = []
    for match in CALL_RE.finditer(pseudocode):
        name = match.group(1)
        lower_name = name.lower()
        if lower_name in CALL_KEYWORDS or lower_name in IGNORED_CALL_NAMES or name == current_name:
            continue
        if name.startswith("__") or name.isupper():
            continue
        callees.append(name)
    return unique_preserve(callees)


def summarize_xref_names(entries, key, limit):
    names = [entry.get(key) for entry in entries or []]
    return unique_preserve(name for name in names if name)[:limit]


def default_summary_path(json_path):
    base_dir = os.path.dirname(os.path.abspath(json_path))
    base_name = os.path.splitext(os.path.basename(json_path))[0]
    return os.path.join(base_dir, f"{base_name}.summary.md")


def format_inline_list(values, limit):
    values = [str(value) for value in values if value]
    if not values:
        return "_none_"
    if len(values) <= limit:
        return ", ".join(f"`{value}`" for value in values)
    shown = ", ".join(f"`{value}`" for value in values[:limit])
    return f"{shown}, ... (+{len(values) - limit} more)"


def build_batch_edges(items):
    known_names = {item.get("name") for item in items if item.get("name")}
    edges = []
    for item in items:
        caller = item.get("name") or item.get("ea") or "<unnamed>"
        for callee in extract_called_functions(item):
            if callee in known_names and callee != caller:
                edges.append((caller, callee))
    return unique_preserve(edges)


def build_markdown_summary(payload, max_list_items):
    items = payload.get("items", [])
    unresolved = payload.get("unresolved", [])
    literal_counter = Counter()
    callee_counter = Counter()

    for item in items:
        literal_counter.update(extract_string_literals(item))
        callee_counter.update(extract_called_functions(item))

    lines = [
        "# FFX IDA Batch Summary",
        "",
        "## Overview",
        "",
        f"- Generated: `{payload.get('generated_at_utc', 'unknown')}`",
        f"- Database: `{payload.get('database_path', 'unknown')}`",
        f"- Input: `{payload.get('input_path', 'unknown')}`",
        f"- Hex-Rays available: `{payload.get('hexrays_available')}`",
        f"- Requested targets: `{len(payload.get('targets') or [])}`",
        f"- Exported items: `{payload.get('item_count', len(items))}`",
        f"- Unresolved targets: `{len(unresolved)}`",
    ]

    targets = payload.get("targets") or []
    if targets:
        lines.append(f"- Target list: {format_inline_list(targets, max_list_items)}")

    if items:
        lines.extend(["", "## Batch Signals", ""])

        item_names = [item.get("name") or item.get("ea") or "<unnamed>" for item in items]
        lines.append(f"- Functions captured: {format_inline_list(item_names, max_list_items)}")

        edges = build_batch_edges(items)
        if edges:
            formatted_edges = [f"`{caller}` -> `{callee}`" for caller, callee in edges[:max_list_items]]
            suffix = ""
            if len(edges) > max_list_items:
                suffix = f", ... (+{len(edges) - max_list_items} more)"
            lines.append(f"- Cross-links inside batch: {', '.join(formatted_edges)}{suffix}")

        if literal_counter:
            top_literals = [f"`{name}` x{count}" for name, count in literal_counter.most_common(max_list_items)]
            lines.append(f"- String literals seen: {', '.join(top_literals)}")

        if callee_counter:
            top_callees = [f"`{name}` x{count}" for name, count in callee_counter.most_common(max_list_items)]
            lines.append(f"- Pseudocode calls seen: {', '.join(top_callees)}")

    if unresolved:
        lines.extend(["", "## Unresolved", ""])
        for entry in unresolved:
            target = entry.get("target", "<unknown>")
            reason = entry.get("reason", "Unknown reason")
            ea = entry.get("ea")
            if ea:
                lines.append(f"- `{target}` at `{ea}`: {reason}")
            else:
                lines.append(f"- `{target}`: {reason}")

    if items:
        lines.extend(["", "## Items", ""])
        for item in items:
            title = item.get("name") or "<unnamed>"
            lines.append(f"### {title} @ `{item.get('ea')}`")
            lines.append("")
            lines.append(f"- Requested as: `{item.get('target')}`")
            lines.append(f"- Size: `{item.get('size')}` bytes")
            lines.append(
                f"- Xrefs: `{len(item.get('xrefs_to') or [])}` incoming, `{len(item.get('xrefs_from') or [])}` outgoing"
            )

            incoming = summarize_xref_names(item.get("xrefs_to"), "from_func_name", max_list_items)
            outgoing = summarize_xref_names(item.get("xrefs_from"), "to_func_name", max_list_items)
            outgoing = [name for name in outgoing if name != title]
            lines.append(f"- Incoming functions: {format_inline_list(incoming, max_list_items)}")
            lines.append(f"- Outgoing functions: {format_inline_list(outgoing, max_list_items)}")

            literals = extract_string_literals(item)
            callees = extract_called_functions(item)
            lines.append(f"- String literals: {format_inline_list(literals, max_list_items)}")
            lines.append(f"- Pseudocode calls: {format_inline_list(callees, max_list_items)}")

            if item.get("decompile_error"):
                lines.append(f"- Decompile error: `{item['decompile_error']}`")

            lines.append("")

    return "\n".join(lines).rstrip() + "\n"


def write_summary(payload, json_path, summary_output, max_list_items):
    output_path = summary_output or default_summary_path(json_path)
    summary = build_markdown_summary(payload, max_list_items)
    os.makedirs(os.path.dirname(os.path.abspath(output_path)), exist_ok=True)
    with open(output_path, "w", encoding="utf-8", newline="\n") as handle:
        handle.write(summary)
    return output_path


def print_item(item, show_pseudocode, max_lines):
    print(f"{item.get('name') or '<unnamed>'} @ {item.get('ea')} size={item.get('size')}")
    if item.get("demangled_name"):
        print(f"  demangled: {item['demangled_name']}")
    print(f"  target: {item.get('target')}")
    print(f"  xrefs_to={len(item.get('xrefs_to') or [])} xrefs_from={len(item.get('xrefs_from') or [])}")
    if item.get("decompile_error"):
        print(f"  decompile_error: {item['decompile_error']}")

    if show_pseudocode and item.get("pseudocode"):
        print("  pseudocode:")
        for line in item["pseudocode"].splitlines()[:max_lines]:
            print(f"    {line}")
    print()


def main(argv):
    parser = argparse.ArgumentParser(description="Read JSON exported by ida_batch_decompile.py")
    parser.add_argument("--input", required=True, help="Path to JSON export")
    parser.add_argument("--query", help="Filter by name, address, target, or pseudocode text")
    parser.add_argument("--show-pseudocode", action="store_true", help="Print pseudocode excerpts")
    parser.add_argument("--max-lines", type=int, default=40, help="Maximum pseudocode lines per item")
    parser.add_argument("--list-unresolved", action="store_true", help="Print unresolved targets too")
    parser.add_argument("--write-summary", action="store_true", help="Write a compact Markdown summary next to the JSON export")
    parser.add_argument("--summary-output", help="Path to the Markdown summary file")
    parser.add_argument("--summary-max-items", type=int, default=8, help="Maximum list entries per summary line")
    args = parser.parse_args(argv)

    payload = load_payload(args.input)
    items = [item for item in payload.get("items", []) if matches(item, args.query)]

    print(f"database: {payload.get('database_path')}")
    print(f"input:    {payload.get('input_path')}")
    print(f"hexrays:  {payload.get('hexrays_available')}")
    print(f"items:    {len(items)} / {payload.get('item_count', 0)}")
    print()

    if args.write_summary:
        summary_path = write_summary(payload, args.input, args.summary_output, args.summary_max_items)
        print(f"summary:  {summary_path}")
        print()

    for item in items:
        print_item(item, args.show_pseudocode, args.max_lines)

    if args.list_unresolved and payload.get("unresolved"):
        print("unresolved:")
        for entry in payload["unresolved"]:
            print(f"  - {entry}")


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
