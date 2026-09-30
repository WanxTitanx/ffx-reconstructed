#!/usr/bin/env python3
"""ORQUESTRADOR da decompilacao: relanca o idat, espera crashar, blacklist, repete.

Loop: lancar idat -> monitorar checkpoint -> quando o processo morrer, adicionar
a funcao do checkpoint na blacklist -> relancar. Roda sozinho por horas.
"""
import os
import subprocess
import sys
import time

sys.stdout.reconfigure(encoding="utf-8", errors="replace")

IDAT = r"C:\IDA\IDA Professional 9.2-Haly\idat.exe"
DB = r"F:\ffx-reconstructed\extras\ffxoficial.exe.i64"
SCRIPT = r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\decompile_complete.py"
OUT_ROOT = r"F:\ffx-reconstructed\pseudocode\complete"
CHECKPOINT = os.path.join(OUT_ROOT, "checkpoint.txt")
BLACKLIST = os.path.join(OUT_ROOT, "blacklist.txt")

LOG = os.path.join(OUT_ROOT, "orchestrator.log")


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
    while True:
        n0 = count_c()
        log(f"== relancando idat (atual: {n0} .c) ==")
        proc = subprocess.Popen(
            [IDAT, "-A", f"-S{SCRIPT}", f"-L{LOG}", DB],
            stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
        )
        # monitora: espera o processo morrer (crash ou fim) ou 20 min
        start = time.time()
        while proc.poll() is None:
            if time.time() - start > 1800:  # 30 min sem morrer = travado
                log("30min sem morrer — matando (travado?)")
                proc.kill()
                break
            time.sleep(10)
        n1 = count_c()
        log(f"processo terminou (exit={proc.returncode}); .c: {n0} -> {n1}")
        if os.path.exists(CHECKPOINT):
            cp = open(CHECKPOINT, encoding="utf-8").read().strip()
            ea = cp.split()[0] if cp else ""
            if ea:
                # adiciona na blacklist se nao estiver
                bl = open(BLACKLIST, encoding="utf-8").read() if os.path.exists(BLACKLIST) else ""
                if ea not in bl:
                    with open(BLACKLIST, "a", encoding="utf-8") as f:
                        f.write(f"{ea}\n")
                    log(f"BLACKLIST +{ea} ({cp[7:60]})")
                else:
                    log(f"ja na blacklist: {ea}")
        # fim? se o checkpoint nao avancou e o count parou, verificar
        if n1 == n0 and n1 > 30000:
            log("count parado acima de 30K — fim?")
        time.sleep(5)


if __name__ == "__main__":
    main()
