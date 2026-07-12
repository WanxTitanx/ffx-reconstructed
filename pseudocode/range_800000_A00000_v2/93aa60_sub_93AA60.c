// Function: sub_93AA60
// Address: 0x93aa60
int __cdecl sub_93AA60(int a1)
{
  int v1; // esi
  int v2; // edi
  int v3; // eax
  int v4; // ecx
  _WORD *v5; // eax
  int v6; // eax
  char Buffer[256]; // [esp+0h] [ebp-10Ch] BYREF
  char v9[8]; // [esp+100h] [ebp-Ch] BYREF

  if ( !a1 || !sub_937940(a1, (int)v9) )
    return 0;
  sprintf(Buffer, "host:/ffx/proj/map/master/%c%c%c%c/%s/guid/rsd/guid.rsd", v9[0], v9[1], v9[2], v9[3], v9);
  v1 = sub_9283B0();
  v2 = sub_93AD60(v1, Buffer);
  if ( v2 && unk_193BF80 && *(_DWORD *)unk_193BF80 )
  {
    v3 = *(_DWORD *)(v1 + 20);
    v4 = *(__int16 *)(v3 + 18);
    if ( v4 > 0 )
    {
      v5 = (_WORD *)(*(_DWORD *)(v3 + 8) + 2 + v3);
      do
      {
        *v5 = 0;
        v5 += 3;
        --v4;
      }
      while ( v4 );
    }
    *(float *)(v1 + 164) = 0.0;
    *(float *)(v1 + 148) = 0.0;
    *(_DWORD *)(v1 + 16) |= 6u;
    if ( unk_193BF80 && *(_DWORD *)unk_193BF80 )
      v6 = *(_DWORD *)(*(_DWORD *)unk_193BF80 + 8);
    else
      v6 = 0;
    *(_DWORD *)(v6 + 28) = v1;
    return v2;
  }
  if ( !v1 )
    return v2;
  sub_928000(v1);
  return v2;
}
