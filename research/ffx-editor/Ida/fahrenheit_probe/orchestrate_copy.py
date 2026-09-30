#!/usr/bin/env python3
"""ORQUESTRADOR COPY: decompile FORCE (cache Hex-Rays) + explore_all (100% explorada)
na ffxoficial_COPY.i64. Loop: lancar idat -> crash -> blacklist -> relancar.
Roda sozinho por horas. Usuario precisa FECHAR o IDA GUI (a COPY liberada).

Rodar:  python work/_fahrenheit_probe/orchestrate_copy.py
"""
import os
import subprocess
import sys
import time

sys.stdout.reconfigure(encoding="utf-8", errors="replace")

IDAT = r"C:\IDA\IDA Professional 9.2-Haly\idat.exe"
DB = r"F:\ffx-reconstructed\extras\ffxoficial_COPY.i64"
SCRIPT = r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\run_copy_full.py"
OUT_ROOT = r"F:\ffx-reconstructed\pseudocode\complete"
CHECKPOINT = os.path.join(OUT_ROOT, "checkpoint.txt")
BLACKLIST = os.path.join(OUT_ROOT, "blacklist.txt")

LOG = os.path.join(OUT_ROOT, "orchestrator_copy.log")


def log(msg):
    line = f"[{time.strftime('%H:%M:%S')}] {msg}"
    print(line, flush=True)
    with open(LOG, "a", encoding="utf-8") as f:
        f.write(line + "\n")


def count_c():
    n = 0
    for _, _, fs in os.walk(OUT_ROOT):
        for f in fs:
            if f.endswith(".c"):
                n += 1
    return n


def main():
    log("== ORQUESTRADOR COPY iniciado (decompile FORCE + explore_all) ==")
    while True:
        n0 = count_c()
        log(f"== relancando idat na COPY (atual: {n0} .c) ==")
        proc = subprocess.Popen(
            [IDAT, "-A", f"-S{SCRIPT}", f"-L{LOG}", DB],
            stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
        )
        start = time.time()
        while proc.poll() is None:
            if time.time() - start > 21600:  # 6h sem morrer = travado
                log("6h sem morrer — matando (travado?)")
                proc.kill()
                break
            time.sleep(10)
        n1 = count_c()
        log(f"processo terminou (exit={proc.returncode}); .c: {n0} -> {n1}")
        if os.path.exists(CHECKPOINT):
            cp = open(CHECKPOINT, encoding="utf-8").read().strip()
            ea = cp.split()[0] if cp else ""
            if ea:
                bl = open(BLACKLIST, encoding="utf-8").read() if os.path.exists(BLACKLIST) else ""
                if ea not in bl:
                    with open(BLACKLIST, "a", encoding="utf-8") as f:
                        f.write(f"{ea}\n")
                    log(f"BLACKLIST +{ea} ({cp[7:60]})")
                else:
                    log(f"ja na blacklist: {ea}")
        time.sleep(5)


if __name__ == "__main__":
    main()
