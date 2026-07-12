// Function: FFX_MagicTimeline_WriteRoot84_88_structural
// Address: 0x817200
// [Jarvis naming goal 2026-06-17] Magic timeline handler; structural writer for runtime root+84/root+88 lane.
__int16 *__cdecl FFX_MagicTimeline_WriteRoot84_88_structural(int a1, __int16 *a2)
{
  __int16 v3; // cx
  int v4; // esi
  int v5; // edx
  int n4096; // ecx
  __int16 *result; // eax
  int n393216; // esi
  int v9; // edi
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  _DWORD *v13; // [esp+Ch] [ebp+8h]

  v3 = *(_WORD *)(a1 + 538);
  v4 = *(_DWORD *)(a1 + 544);
  v5 = a1 + 768;
  v13 = (_DWORD *)(a1 + 768);
  n4096 = v3 & 0xF000;
  if ( n4096 )
  {
    result = a2;
    if ( n4096 == 4096 )
    {
      n393216 = a2[1] << 8;
      v9 = a2[2] << 8;
      v10 = a2[3] << 8;
      v13[42] = sub_7FF1F0(*(float **)(v5 + 12), n393216);
      v11 = n393216 + v13[3];
      v13[40] = v11;
      v12 = v9 + v11;
      v13[43] = n393216;
      v13[41] = v9;
      v13[21] = v12;
      v13[22] = v12;
      v13[44] = v10;
      v13[10] = off_C498DC;
      v13[11] = off_C498DC;
      (*(void (__cdecl **)(_DWORD *))(v13[20] + 96))(v13);
      return a2 + 4;
    }
  }
  else
  {
    if ( *(_DWORD *)(v4 + 188) )
    {
      sub_7FF0F0(*(_DWORD *)(a1 + 936), *(_DWORD *)(v4 + 188));
      *(_DWORD *)(v4 + 188) = 0;
    }
    return a2 + 1;
  }
  return result;
}
