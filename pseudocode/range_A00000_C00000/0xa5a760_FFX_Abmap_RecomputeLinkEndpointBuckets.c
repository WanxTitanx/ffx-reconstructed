// Function: FFX_Abmap_RecomputeLinkEndpointBuckets
// Address: 0xa5a760
// Size: 0x9d
// Prototype: int __cdecl(unsigned __int16 *)

// [Jarvis naming goal 2026-06-17 pass2] Recomputes link endpoint spatial buckets using Unknown6 formula from endpoint node positions.
int __cdecl FFX_Abmap_RecomputeLinkEndpointBuckets(unsigned __int16 *a1)
{
  int v1; // esi
  int result; // eax

  a1[4] = (*(__int16 *)(dword_2305834[0] + 40 * *a1 + 2056) + 2560) / 256
        + 20 * ((*(__int16 *)(dword_2305834[0] + 40 * *a1 + 2058) + 2336) / 256);
  v1 = dword_2305834[0] + 40 * a1[1];
  result = (*(__int16 *)(v1 + 2056) + 2560) / 256 + 20 * ((*(__int16 *)(v1 + 2058) + 2336) / 256);
  a1[5] = result;
  return result;
}

