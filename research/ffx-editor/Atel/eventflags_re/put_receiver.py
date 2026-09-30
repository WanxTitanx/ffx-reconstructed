#!/usr/bin/env python3
# PUT receiver: saves uploaded DB to ffxoficial.exe.i64.new4 (never overwrites live file).
# Pattern from EVENTFLAGS-RE mission (2026-09-14). Listens 0.0.0.0:8001, path /db.
import http.server, os
OUT = "/mnt/ssd-kingston/ffx-reconstructed/extras/ffxoficial.exe.i64.new4"
class H(http.server.BaseHTTPRequestHandler):
    def do_PUT(self):
        n = int(self.headers.get("Content-Length", 0))
        with open(OUT + ".part", "wb") as f:
            remaining = n
            while remaining > 0:
                chunk = self.rfile.read(min(1 << 20, remaining))
                if not chunk: break
                f.write(chunk); remaining -= len(chunk)
        os.replace(OUT + ".part", OUT)
        self.send_response(200); self.send_header("Content-Length", "2"); self.end_headers()
        self.wfile.write(b"ok")
        print(f"PUT {n} bytes -> {OUT}", flush=True)
    def log_message(self, *a): pass
http.server.HTTPServer(("0.0.0.0", 8001), H).serve_forever()
