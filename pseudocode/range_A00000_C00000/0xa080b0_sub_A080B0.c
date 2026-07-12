// Function: sub_A080B0
// Address: 0xa080b0
// Size: 0x74
// Prototype: 

int __cdecl sub_A080B0(_DWORD *a1)
{
  unsigned int v1; // ebx
  int v2; // esi
  _DWORD *v3; // esi
  int v4; // edi
  int result; // eax
  _DWORD *v6; // eax
  int v7; // eax
  int v8; // [esp+Ch] [ebp-4h]

  v1 = a1[15];
  v2 = a1[12];
  if ( v2 )
    v3 = (_DWORD *)(v2 - 4);
  else
    v3 = 0;
  v4 = 0;
  v8 = *(_DWORD *)(a1[11] + 28);
  if ( !v1 )
    return 0;
  while ( 1 )
  {
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*v3 + 4))(v3, 0, 0);
    if ( result )
      break;
    v6 = (_DWORD *)v3[2];
    if ( v6 )
    {
      if ( *v6 )
      {
        v7 = sub_A161B0(v3);
        result = sub_A18C80(&unk_1943DA0, v7);
        if ( result )
          break;
      }
    }
    v3 = (_DWORD *)((char *)v3 + v8);
    if ( ++v4 >= v1 )
      return 0;
  }
  return result;
}

