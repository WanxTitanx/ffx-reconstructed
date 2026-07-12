// Function: sub_9A0C00
// Address: 0x9a0c00
int __thiscall sub_9A0C00(_DWORD *this, int a2, int a3)
{
  int v3; // edx
  int v5; // ecx
  int v6; // ebx
  int v7; // ecx
  int v8; // edx
  int v10; // edx
  int v11; // edi
  _DWORD *v12; // eax
  int v13; // [esp+10h] [ebp+8h]

  ++unk_193F63C;
  v3 = a3;
  v5 = a2;
  if ( *(_DWORD *)(a2 + 12) > *(_DWORD *)(a3 + 12) )
  {
    v5 = a3;
    v3 = a2;
  }
  v6 = *(_DWORD *)(v3 + 12);
  v13 = *(_DWORD *)(v5 + 12);
  v7 = ~((((9
          * (((~((v13 | (v6 << 16)) << 15) + (v13 | (v6 << 16))) >> 10)
           ^ (~((v13 | (v6 << 16)) << 15) + (v13 | (v6 << 16))))) >> 6)
        ^ (9
         * (((~((v13 | (v6 << 16)) << 15) + (v13 | (v6 << 16))) >> 10)
          ^ (~((v13 | (v6 << 16)) << 15) + (v13 | (v6 << 16)))))) << 11)
     + (((9
        * (((~((v13 | (v6 << 16)) << 15) + (v13 | (v6 << 16))) >> 10)
         ^ (~((v13 | (v6 << 16)) << 15) + (v13 | (v6 << 16))))) >> 6)
      ^ (9
       * (((~((v13 | (v6 << 16)) << 15) + (v13 | (v6 << 16))) >> 10) ^ (~((v13 | (v6 << 16)) << 15) + (v13 | (v6 << 16))))));
  v8 = (*(this + 3) - 1) & (v7 ^ (v7 >> 16));
  if ( v8 >= *(this + 9) )
    return 0;
  v10 = *(_DWORD *)(*(this + 11) + 4 * v8);
  if ( v10 == -1 )
    return 0;
  v11 = *(this + 4);
  while ( 1 )
  {
    v12 = (_DWORD *)(v11 + 16 * v10);
    v11 = *(this + 4);
    if ( *(_DWORD *)(*v12 + 12) == v13 && *(_DWORD *)(v12[1] + 12) == v6 )
      break;
    v10 = *(_DWORD *)(*(this + 16) + 4 * v10);
    if ( v10 == -1 )
      return 0;
  }
  return v11 + 16 * v10;
}
