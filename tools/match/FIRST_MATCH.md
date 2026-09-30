# First byte-identical match: FFX_memcmp

Target: `FFX_memcmp` @ `0x401020`, 112 bytes, `SHA256 pilot_ffx_memcmp.ref.bin`.

Source (`src/ffx_memcmp.c`):

```c
#include <string.h>
int __cdecl FFX_memcmp(const void *p1, const void *p2, unsigned len)
{
    if (!len)
        return 0;
    return memcmp(p1, p2, len);
}
```

Toolchain: VS2012 Express (17.00.50727.1), flags `/nologo /c /GS- /O2 /MD /Oy- /Oi /GL`, link with `/LTCG`.

Provenance notes:

- The dword loop (`sub ecx,4; jb` + `jae` loop), the `-4..-1` tail compares, and the shared `sbb/or` sign block are all VS2012's `/Oi` memcmp intrinsic expansion, not hand-written C. Hand-written loops can imitate the shape but never the exact bytes.
- The `lea ebx,[ebx]` loop-alignment padding appears only under `/GL`+`/LTCG` link-time codegen, not in the plain `/O2` object.
- The `if (!len) return 0` guard is required: without it the prologue lacks the `test/jne/xor/pop/ret` prefix.
- `/Oy-` (frame pointer) is required for the `push ebp; mov ebp,esp` prologue.

Reproduce: build `src/ffx_memcmp.c` with the flags above, link `/LTCG`, extract `.text`, compare with `pilot_ffx_memcmp.ref.bin`.
