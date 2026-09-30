#!/usr/bin/env python3
"""vm_pull_file.py — pull a file from windows11-dev-next via QGA guest-file-read.

Usage: vm_pull_file.py <guest-windows-path> <local-path>
(QA-WINDOWS lane FFX-STRUCTURES, 2026-09-14; the HTTP server only serves host->guest,
 so guest->host transfers go through QGA file handles.)
"""
import base64
import json
import subprocess
import sys

VM = "windows11-dev-next"


def agent(payload: dict) -> dict:
    result = subprocess.run(
        ["virsh", "-c", "qemu:///system", "qemu-agent-command", VM, json.dumps(payload)],
        capture_output=True, text=True, check=True)
    return json.loads(result.stdout)


def main() -> None:
    guest_path, local_path = sys.argv[1], sys.argv[2]
    opened = agent({"execute": "guest-file-open",
                    "arguments": {"path": guest_path, "mode": "r"}})
    handle = opened["return"]
    try:
        buf = b""
        while True:
            chunk = agent({"execute": "guest-file-read",
                           "arguments": {"handle": handle, "count": 65536}})
            data = chunk["return"]
            # this qemu build returns "buf-b64" (not the documented "buf")
            buf += base64.b64decode(data.get("buf-b64", data.get("buf", "")))
            if data.get("eof"):
                break
    finally:
        agent({"execute": "guest-file-close", "arguments": {"handle": handle}})
    with open(local_path, "wb") as sink:
        sink.write(buf)
    print(f"wrote {local_path} ({len(buf)} bytes) from {guest_path}")


if __name__ == "__main__":
    main()
