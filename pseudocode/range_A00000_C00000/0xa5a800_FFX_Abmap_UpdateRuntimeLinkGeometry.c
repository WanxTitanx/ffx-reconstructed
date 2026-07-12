// Function: FFX_Abmap_UpdateRuntimeLinkGeometry
// Address: 0xa5a800
// Size: 0xda
// Prototype: int()

// [Jarvis naming goal 2026-06-17 pass2] Iterates ABMAP link records and updates runtime geometry/curve data from endpoint positions and optional midpoint/control node.
int FFX_Abmap_UpdateRuntimeLinkGeometry()
{
  int result; // eax
  int v1; // ebx
  int v2; // edi
  unsigned __int16 *v3; // esi
  double v4; // st7
  int v5; // eax
  int v6; // eax
  int v7; // [esp+4h] [ebp-4Ch]
  int v8[4]; // [esp+18h] [ebp-38h] BYREF
  int v9[4]; // [esp+28h] [ebp-28h] BYREF
  int v10[4]; // [esp+38h] [ebp-18h] BYREF
  float v11; // [esp+48h] [ebp-8h]
  float v12; // [esp+4Ch] [ebp-4h]

  result = dword_2305834[0];
  v1 = *(__int16 *)(dword_2305834[0] + 4);
  v2 = *(_DWORD *)(dword_2305834[0] + 71272);
  v3 = (unsigned __int16 *)(dword_2305834[0] + 43016);
  if ( *(_WORD *)(dword_2305834[0] + 4) )
  {
    do
    {
      v7 = *v3;
      --v1;
      *((_DWORD *)v3 + 4) = v2;
      v11 = sub_A5B4C0(v7, v9);
      v4 = sub_A5B4C0(v3[1], v10);
      v5 = v3[2];
      v12 = v4;
      if ( (_WORD)v5 == 0xFFFF )
      {
        v6 = sub_A581F0(v2, (int)v9, (int)v10, v11, v12, (int)v3 + 13);
      }
      else
      {
        sub_A5B4C0(v5, v8);
        v6 = sub_A57710(v2, (int)v9, (int)v10, (int)v8, v11, v12, (int)v3 + 13);
      }
      v3 += 10;
      v2 = v6;
    }
    while ( v1 );
    result = dword_2305834[0];
  }
  *(_DWORD *)(result + 71272) = v2;
  return result;
}

