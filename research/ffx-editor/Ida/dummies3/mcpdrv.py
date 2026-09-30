#!/usr/bin/env python3
# PROMOTED 2026-09-18 (lane Jarvis-TOOLS-REPAIR) from work/_dummies3/ (gitignored scratch).
# Origin: DUMMIES3 rename sweep 2026-09-17/18 (3,656/3,662 renames applied+verified,
#   doc docs/reverse/FFX_DUMMIES3_2026-09-17.md, CSVs docs/reverse/data/wave13/dummies3_*.csv).
# Promoted per WAVE-LEDGER recommendation: the authoritative post-rename verification
# method (names-index dump + per-addr reconcile) must live in research_tools/, not scratch.
# Requires the live idalib-mcp endpoint (IDA_MCP_URL, default 192.168.122.85:8745).
"""Persistent JSON-RPC driver for idalib-mcp (FFX.exe DB census lane).

Keeps one MCP session across calls; auto-follows the server's
"Output truncated. Run: curl -o ... <url>" spill mechanism and returns the
full payload (parsed JSON when possible, else raw text).
"""
import json, os, re, sys, time, urllib.request

URL = os.environ.get("IDA_MCP_URL", "http://192.168.122.85:8745/mcp")
_SPILL = re.compile(r'curl -o \S+ (http://\S+)')


class Mcp:
    def __init__(self, url=URL):
        self.url = url
        self.sess = None
        self.calls = 0
        self._init()

    def _post(self, payload):
        h = {'Content-Type': 'application/json',
             'Accept': 'application/json, text/event-stream'}
        if self.sess:
            h['mcp-session-id'] = self.sess
        req = urllib.request.Request(self.url, data=json.dumps(payload).encode(),
                                     headers=h)
        resp = urllib.request.urlopen(req, timeout=900)
        sid = resp.headers.get('mcp-session-id')
        if sid:
            self.sess = sid
        body = resp.read().decode()
        out = []
        for line in body.splitlines():
            if line.startswith('data: '):
                out.append(line[6:])
            elif line and not line.startswith('event:') and not line.startswith(':'):
                out.append(line)
        return '\n'.join(out)

    def _init(self):
        last = None
        for attempt in range(12):
            try:
                self._post({'jsonrpc': '2.0', 'id': 1, 'method': 'initialize',
                            'params': {'protocolVersion': '2025-03-26', 'capabilities': {},
                                       'clientInfo': {'name': 'census-lane', 'version': '1'}}})
                self._post({'jsonrpc': '2.0', 'method': 'notifications/initialized'})
                return
            except Exception as e:
                last = e
                sys.stderr.write(f'init retry {attempt+1}: {e}\n')
                time.sleep(10 * (attempt + 1) if attempt < 6 else 90)
        raise last

    def call(self, tool, args, retries=8):
        self.calls += 1
        for attempt in range(retries):
            try:
                body = self._post({'jsonrpc': '2.0', 'id': 1000 + self.calls,
                                   'method': 'tools/call',
                                   'params': {'name': tool, 'arguments': args}})
                break
            except Exception as e:
                if attempt == retries - 1:
                    raise
                sys.stderr.write(f'  call retry {attempt+1} {tool}: {e}\n')
                time.sleep(min(60, 4 * (attempt + 1)))
        try:
            d = json.loads(body)
        except Exception:
            return body
        res = d.get('result', d)
        if isinstance(res, dict) and 'content' in res:
            texts = [c['text'] for c in res['content'] if c.get('type') == 'text']
            txt = '\n'.join(texts)
        elif isinstance(res, dict) and res.get('isError'):
            txt = json.dumps(res)
        else:
            return res
        m = _SPILL.search(txt)
        if m:
            for attempt in range(3):
                try:
                    full = urllib.request.urlopen(m.group(1), timeout=900).read().decode()
                    break
                except Exception:
                    if attempt == 2:
                        return txt
                    time.sleep(1 + attempt)
            try:
                return json.loads(full)
            except Exception:
                return full
        try:
            return json.loads(txt)
        except Exception:
            return txt


def scan_pattern(m, pattern, start, end, code_only=True, include='disasm',
                 limit=500, depth=0):
    """Adaptive range scan: subdivides [start,end) while a chunk saturates the
    limit. Returns list of hits."""
    r = m.call('search_text', {'pattern': pattern, 'regex': True,
                               'include': include, 'code_only': code_only,
                               'start': hex(start), 'end': hex(end),
                               'limit': limit})
    if not isinstance(r, dict):
        return []
    n = r.get('n', 0)
    done = r.get('cursor', {}).get('done', True)
    hits = r.get('hits', [])
    if n >= limit and (end - start) > 0x1000 and depth < 14:
        mid = start + (end - start) // 2
        return (scan_pattern(m, pattern, start, mid, code_only, include, limit, depth + 1)
                + scan_pattern(m, pattern, mid, end, code_only, include, limit, depth + 1))
    if n >= limit:
        sys.stderr.write(f'WARN saturated chunk {hex(start)}-{hex(end)} n={n}\n')
    return hits


if __name__ == '__main__':
    m = Mcp()
    tool = sys.argv[1]
    args = json.loads(sys.argv[2]) if len(sys.argv) > 2 else {}
    out = m.call(tool, args)
    print(json.dumps(out) if not isinstance(out, str) else out)
