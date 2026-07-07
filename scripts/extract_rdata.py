"""
FFX .rdata Extractor — extrai o segmento .rdata do ffxoficial.exe
e gera um arquivo C com os dados binários embedidos.

Output: src/data/rdata_dump.h (array C com ~1MB)
"""
import os
import sys

OUTPUT_DIR = os.path.join(os.path.dirname(__file__), "..", "..", "src", "data")
OUTPUT_FILE = os.path.join(OUTPUT_DIR, "rdata_dump.h")

RDATA_START = 0xB0C8C0
RDATA_END = 0xC0A000
RDATA_SIZE = RDATA_END - RDATA_START
CHUNK_SIZE = 8192

HEADER = """#ifndef FFX_RDATA_DUMP_H
#define FFX_RDATA_DUMP_H

#include <stdint.h>

#define FFX_RDATA_START 0xB0C8C0u
#define FFX_RDATA_END   0xC0A000u
#define FFX_RDATA_SIZE  0x{size:X}u

static const uint8_t g_ffx_rdata[FFX_RDATA_SIZE] = {{
"""

FOOTER = """}};

#endif
"""


def main():
    os.makedirs(OUTPUT_DIR, exist_ok=True)

    print(f"Extracting .rdata: 0x{RDATA_START:X} - 0x{RDATA_END:X} ({RDATA_SIZE} bytes)")
    print(f"Output: {OUTPUT_FILE}")
    print(f"Chunks: {(RDATA_SIZE + CHUNK_SIZE - 1) // CHUNK_SIZE}")

    print("Script preparado. Execute a extracao via IDA MCP:")
    print(f"  idalib_get_bytes em chunks de {CHUNK_SIZE} bytes")
    print(f"  Concatenar e escrever em {OUTPUT_FILE}")
    print("")
    print("NOTA: O GLM-5.2 ira coordenar a extracao via IDA MCP em chunks.")
    print("Este script so gera o template.")


if __name__ == "__main__":
    main()
