#!/usr/bin/env python3
"""
Extract pseudocode for ALL functions in 0x400000-0x600000 from IDA MCP.
Uses analyze_batch with proper truncation handling.
"""
import json, os, re, sys, time, urllib.request, urllib.error, html

MCP_URL = "http://127.0.0.1:53407/mcp"
DATABASE = "76b991e4"
OUT_DIR = os.path.dirname(os.path.abspath(__file__))
FUNCS_FILE = os.path.join(OUT_DIR, "funcs_400000_600000.json")
PROCESSED_FILE = os.path.join(OUT_DIR, "_processed.txt")
BATCH_SIZE = 30

def json_rpc(method, params):
    payload = {"jsonrpc":"2.0","method":"tools/call",
               "params":{"name":method,"arguments":params},"id":1}
    data = json.dumps(payload).encode()
    req = urllib.request.Request(MCP_URL, data, {"Content-Type":"application/json"})
    try:
        with urllib.request.urlopen(req, timeout=600) as r:
            return json.loads(r.read().decode())
    except Exception as e:
        return {"error":str(e)}

def get_output_url(text):
    m = re.search(r'curl -o \S+ (http\S+)', text)
    return m.group(1) if m else None

def sanitize(s):
    return "".join(c if c.isalnum() or c in "._-" else "_" for c in s)

def write_func_file(addr, name, size, proto, code):
    safe = sanitize(name)
    a = addr.replace("0x","").lower()
    path = os.path.join(OUT_DIR, f"{a}_{safe}.c")
    header = f"// Function: {name}\n// Address: {addr}\n// Size: {size}\n"
    if proto and proto != "null":
        header += f"// Prototype: {proto}\n"
    with open(path, "w", encoding="utf-8") as f:
        f.write(header + "\n" + (code or "// DECOMPILE FAILED\n"))

def parse_batch_result(text):
    """Parse analyze_batch result from text, handling truncation."""
    # Check if truncated
    url = get_output_url(text)
    if url:
        try:
            with urllib.request.urlopen(url, timeout=60) as r:
                return json.loads(r.read().decode())
        except:
            return None
    
    # Try direct JSON parse
    try:
        return json.loads(text)
    except json.JSONDecodeError:
        return None

def process_batch(batch):
    """Process a batch of functions and write their files."""
    queries = []
    for f in batch:
        queries.append({
            "addr": f["addr"],
            "include_decompile": True,
            "include_disasm": False,
            "include_xrefs": False,
            "include_callers": False,
            "include_callees": False,
            "include_strings": False,
            "include_constants": False,
            "include_basic_blocks": False,
            "include_proto": True
        })
    
    resp = json_rpc("idalib_analyze_batch", {
        "database": DATABASE,
        "queries": queries
    })
    
    if "error" in resp and resp["error"]:
        print(f"  MCP ERROR: {resp['error']}")
        return 0, len(batch)
    
    content = resp.get("result", {}).get("content", [])
    if not content:
        print(f"  No content in response")
        return 0, len(batch)
    
    text = content[0].get("text", "")
    results = parse_batch_result(text)
    
    if results is None:
        print(f"  Failed to parse results (text len={len(text)})")
        return 0, len(batch)
    
    if not isinstance(results, list):
        print(f"  Results not a list: {type(results)}")
        return 0, len(batch)
    
    success = 0
    for i, r in enumerate(results):
        if not isinstance(r, dict):
            continue
        analysis = r.get("analysis", {})
        if not analysis:
            continue
        addr = r.get("addr", batch[i]["addr"])
        name = r.get("name", batch[i]["name"])
        size = analysis.get("size", batch[i].get("size", "?"))
        proto = analysis.get("prototype", "")
        code = analysis.get("decompile", "")
        write_func_file(addr, name, size, proto, code)
        success += 1
    
    fail = len(batch) - success
    return success, fail

def main():
    with open(FUNCS_FILE, "r", encoding="utf-8") as f:
        all_funcs = json.load(f)
    
    total = len(all_funcs)
    print(f"Loaded {total} functions to decompile\n")
    
    # Load processed set
    processed = set()
    if os.path.exists(PROCESSED_FILE):
        with open(PROCESSED_FILE, "r") as f:
            processed = set(line.strip() for line in f if line.strip())
        print(f"Already processed: {len(processed)}")
    
    remaining = [f for f in all_funcs if f"{f['addr']}_{f['name']}" not in processed]
    print(f"Remaining: {len(remaining)}\n")
    
    if not remaining:
        print("All done!")
        return
    
    total_batches = (len(remaining) + BATCH_SIZE - 1) // BATCH_SIZE
    success_total = 0
    fail_total = 0
    start = time.time()
    
    for bi in range(0, len(remaining), BATCH_SIZE):
        batch = remaining[bi:bi + BATCH_SIZE]
        bn = bi // BATCH_SIZE + 1
        
        print(f"[{bn}/{total_batches}] Processing {len(batch)} funcs @ {batch[0]['addr']}...", end=" ", flush=True)
        
        s, f = process_batch(batch)
        success_total += s
        fail_total += f
        
        # Mark as processed
        with open(PROCESSED_FILE, "a") as pf:
            for func in batch:
                pf.write(f"{func['addr']}_{func['name']}\n")
        
        elapsed = time.time() - start
        rate = success_total / elapsed if elapsed > 0 else 0
        done = success_total + fail_total
        remaining_count = total - done
        eta = remaining_count / rate if rate > 0 else 0
        
        print(f"OK={s} FAIL={f} | Total: {success_total}/{total} | {rate:.1f}/s | ETA: {eta:.0f}s")
    
    elapsed = time.time() - start
    print(f"\n{'='*60}")
    print(f"COMPLETE: {success_total} OK, {fail_total} FAIL, {elapsed:.0f}s")
    print(f"{'='*60}")

if __name__ == "__main__":
    main()
