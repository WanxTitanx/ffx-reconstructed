// Function: sub_A3C570
// Address: 0xa3c570
// Size: 0xbb
// Prototype: 

int __cdecl sub_A3C570(_WORD *a1)
{
  int v1; // eax
  _DWORD *v2; // edx
  int result; // eax
  int v4; // esi
  int v5; // eax
  int v6; // [esp+8h] [ebp-4h] BYREF

  v1 = sub_A3B590();
  v2 = dword_1A858B4;
  v6 = v1;
  if ( v1 == dword_1A858B4[480] )
  {
    (*(void (__stdcall **)(_DWORD, int, int *, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 132))(
      dword_1A858B4[1],
      1,
      &v6,
      dword_1A858B4[481]);
    result = (*(int (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 172))(
               dword_1A858B4[1],
               dword_1A858B4[dword_1A858B4[484] + 491]);
    *a1 |= 0x20u;
    ++a1[6];
  }
  else
  {
    v4 = 0;
    if ( (*(_BYTE *)(dword_1A858B4[683] + 20) & 0xC) != 0 )
    {
      v5 = sub_A3B840((int)a1);
      v2 = dword_1A858B4;
      v4 = v5;
    }
    (*(void (__stdcall **)(_DWORD, int, int *, int))(*(_DWORD *)v2[1] + 132))(v2[1], 1, &v6, v4);
    result = (*(int (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 172))(
               dword_1A858B4[1],
               dword_1A858B4[491]);
    *a1 |= 0x20u;
    ++a1[6];
  }
  return result;
}

