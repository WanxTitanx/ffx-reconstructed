#!/usr/bin/env python3
"""explore_all_live.py — explora 100% a db ABERTA no GUI (via MCP, sem qexit).
Marca todos os bytes undefined como dados/align. Nao fecha o IDA."""
import sys

sys.path.insert(0, r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe")
import explore_all  # noqa: E402


if __name__ == "__main__":
    import ida_auto
    ida_auto.auto_wait()
    # roda o main sem o qexit (chama o corpo manualmente)
    # explore_all.main() tem qexit no final — replicamos aqui sem ele
    from importlib import reload
    import explore_all as ea

    # substitui qexit por no-op
    import ida_pro
    ida_pro.qexit = lambda code: print(f"(qexit ignorado: {code})", flush=True)
    ea.main()
    print("EXPLORE LIVE COMPLETO — db modificada (salve com Ctrl+S)", flush=True)
