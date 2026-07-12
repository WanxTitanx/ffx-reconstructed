// Function: sub_A07F00
// Address: 0xa07f00
// Size: 0xad
// Prototype: 

int __cdecl sub_A07F00(_DWORD *a1)
{
  int v1; // esi
  _DWORD *v2; // esi
  int v3; // edi
  int result; // eax
  _DWORD *v5; // eax
  int v6; // ebx
  unsigned int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  v1 = a1[12];
  v7 = a1[15];
  if ( v1 )
    v2 = (_DWORD *)(v1 - 4);
  else
    v2 = 0;
  v3 = 0;
  v8 = *(_DWORD *)(a1[11] + 28);
  if ( !a1[15] )
    return 0;
  while ( 1 )
  {
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*v2 + 4))(v2, 0, 0);
    if ( result )
      break;
    v5 = (_DWORD *)v2[2];
    if ( v5 && *v5 )
    {
      v6 = sub_A161B0(v2);
      result = sub_A185A0(&unk_1943DA0, v6);
      if ( result )
        return result;
      v2[1005] = sub_56CD50("FocusPlaneDistance");
      v2[1006] = sub_56CD50("FocusRange");
      v2[1007] = sub_56CD50("FocusBlurRange");
    }
    v2 = (_DWORD *)((char *)v2 + v8);
    if ( ++v3 >= v7 )
      return 0;
  }
  return result;
}

