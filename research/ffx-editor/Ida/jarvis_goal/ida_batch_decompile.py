# RECOVERED 2026-09-18 (lane Jarvis-TOOLS-REPAIR): source restored from git history
# commit 53d82b2a, original path RuntimeTools/FFXMapViewerWeb/work/reverse/ida/scripts/<name>.
# The work/reverse/ida/scripts/ tree was never committed at its original location;
# only __pycache__/*.pyc + this history copy survived. Cited by docs/reverse/* + SESSION_HANDOFF.
import datetime
import json
import os
import sys
import traceback

import idautils
import ida_auto
import ida_funcs
import ida_hexrays
import ida_kernwin
import ida_lines
import ida_name
import ida_nalt
import idc


BADADDR = idc.BADADDR
CONFIG_ENV = "FFX_IDA_BATCH_CONFIG"


def load_config():
    config_path = os.environ.get(CONFIG_ENV)
    if not config_path:
        raise RuntimeError(f"Missing {CONFIG_ENV} environment variable.")

    with open(config_path, "r", encoding="utf-8-sig") as handle:
        config = json.load(handle)

    config["config_path"] = config_path
    return config


def ensure_hexrays():
    if not ida_hexrays.init_hexrays_plugin():
        return False
    return True


def strip_color_tags(line):
    return ida_lines.tag_remove(line.line if hasattr(line, "line") else str(line))


def normalize_target(raw_target):
    if isinstance(raw_target, dict):
        return raw_target

    text = str(raw_target).strip()
    if not text:
        return {"type": "empty", "value": text}

    if text.lower().startswith("0x"):
        return {"type": "address", "value": text}

    if text.isdigit():
        return {"type": "address", "value": hex(int(text))}

    if text.endswith("*"):
        return {"type": "prefix", "value": text[:-1]}

    return {"type": "name", "value": text}


def find_functions_by_prefix(prefix):
    matches = []
    prefix_lower = prefix.lower()
    for func_ea in idautils.Functions():
        func_name = ida_name.get_name(func_ea) or ""
        if func_name.lower().startswith(prefix_lower):
            matches.append(func_ea)
    return matches


def resolve_function_eas(target):
    target_type = target.get("type")
    value = target.get("value")

    if target_type == "address":
        ea = int(str(value), 16)
        func = ida_funcs.get_func(ea)
        if func:
            return [func.start_ea]
        return []

    if target_type == "name":
        ea = ida_name.get_name_ea(BADADDR, value)
        if ea != BADADDR:
            func = ida_funcs.get_func(ea)
            if func:
                return [func.start_ea]
        return []

    if target_type == "prefix":
        return find_functions_by_prefix(value)

    return []


def format_xrefs(xrefs, limit):
    items = []
    for xref in xrefs[:limit]:
        from_func = ida_funcs.get_func(xref.frm)
        to_func = ida_funcs.get_func(xref.to)
        items.append(
            {
                "from_ea": hex(xref.frm),
                "to_ea": hex(xref.to),
                "type": int(xref.type),
                "from_name": ida_name.get_name(xref.frm) or "",
                "to_name": ida_name.get_name(xref.to) or "",
                "from_func_name": ida_name.get_name(from_func.start_ea) if from_func else "",
                "to_func_name": ida_name.get_name(to_func.start_ea) if to_func else "",
            }
        )
    return items


def decompile_function(func_ea, include_pseudocode, max_xrefs, hexrays_available):
    func = ida_funcs.get_func(func_ea)
    if not func:
        raise RuntimeError(f"No function found at {hex(func_ea)}")

    result = {
        "ea": hex(func.start_ea),
        "end_ea": hex(func.end_ea),
        "size": int(func.end_ea - func.start_ea),
        "name": ida_name.get_name(func.start_ea) or "",
        "demangled_name": idc.demangle_name(ida_name.get_name(func.start_ea) or "", 0) or "",
        "flags": int(func.flags),
        "xrefs_to": format_xrefs(list(idautils.XrefsTo(func.start_ea)), max_xrefs),
        "xrefs_from": format_xrefs(list(idautils.XrefsFrom(func.start_ea)), max_xrefs),
        "pseudocode": None,
        "decompile_error": None,
    }

    if include_pseudocode and hexrays_available:
        try:
            cfunc = ida_hexrays.decompile(func.start_ea)
            result["pseudocode"] = "\n".join(strip_color_tags(line) for line in cfunc.get_pseudocode())
        except Exception as exc:
            result["decompile_error"] = str(exc)
    elif include_pseudocode:
        result["decompile_error"] = "Hex-Rays decompiler is not available."

    return result


def build_output(config, hexrays_available):
    include_pseudocode = bool(config.get("include_pseudocode", True))
    max_xrefs = int(config.get("max_xrefs", 20))
    target_limit = int(config.get("target_limit", 100))
    raw_targets = config.get("targets") or []

    items = []
    unresolved = []

    for raw_target in raw_targets:
        target = normalize_target(raw_target)
        resolved = resolve_function_eas(target)
        if not resolved:
            unresolved.append({"target": raw_target, "reason": "No function match found"})
            continue

        if len(resolved) > target_limit:
            unresolved.append(
                {
                    "target": raw_target,
                    "reason": f"Matched {len(resolved)} functions; limit is {target_limit}",
                }
            )
            continue

        for ea in resolved:
            try:
                item = decompile_function(ea, include_pseudocode, max_xrefs, hexrays_available)
                item["target"] = raw_target
                items.append(item)
            except Exception as exc:
                unresolved.append({"target": raw_target, "ea": hex(ea), "reason": str(exc)})

    return {
        "generated_at_utc": datetime.datetime.utcnow().isoformat() + "Z",
        "database_path": idc.get_idb_path(),
        "input_path": ida_nalt.get_input_file_path(),
        "hexrays_available": bool(hexrays_available),
        "targets": raw_targets,
        "item_count": len(items),
        "unresolved": unresolved,
        "items": items,
    }


def write_output(payload, output_path):
    os.makedirs(os.path.dirname(output_path), exist_ok=True)
    with open(output_path, "w", encoding="utf-8") as handle:
        json.dump(payload, handle, indent=2, ensure_ascii=False)


def main():
    config = load_config()
    ida_auto.auto_wait()
    hexrays_available = ensure_hexrays()

    output_path = config.get("output_path")
    if not output_path:
        raise RuntimeError("Config is missing output_path.")

    payload = build_output(config, hexrays_available)
    write_output(payload, output_path)
    ida_kernwin.msg(f"[ffx_ida_batch] wrote {payload['item_count']} item(s) to {output_path}\n")
    idc.qexit(0)


if __name__ == "__main__":
    try:
        main()
    except Exception:
        error_path = os.environ.get("FFX_IDA_BATCH_ERROR")
        message = traceback.format_exc()
        ida_kernwin.msg(f"[ffx_ida_batch] fatal error:\n{message}\n")
        if error_path:
            try:
                with open(error_path, "w", encoding="utf-8") as handle:
                    handle.write(message)
            except Exception:
                pass
        idc.qexit(1)
