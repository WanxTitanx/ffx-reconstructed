// Function: sub_938080
// Address: 0x938080
int __cdecl sub_938080(int a1, int a2)
{
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v5; // ecx
  _WORD *v6; // eax
  char Buffer[256]; // [esp+0h] [ebp-10Ch] BYREF
  char v9; // [esp+100h] [ebp-Ch] BYREF
  char v10; // [esp+101h] [ebp-Bh]
  char v11; // [esp+102h] [ebp-Ah]
  char v12; // [esp+103h] [ebp-9h]

  if ( !a1 || !sub_937940(a1, (int)&v9) )
    return 0;
  if ( a2 )
    sprintf(Buffer, "host:/ffx/proj/map/master/%c%c%c%c/%s/guid/rsd/guid%02d.rsd", v9, v10, v11, v12, &v9, a2);
  else
    sprintf(Buffer, "host:/ffx/proj/map/master/%c%c%c%c/%s/guid/rsd/guid.rsd", v9, v10, v11, v12, &v9);
  v2 = sub_62FBE0(Buffer, 1);
  if ( !v2 )
    return 0;
  FFX_FileIO_IopDevice_Close(v2);
  v3 = sub_9283B0();
  if ( sub_93AD60(v3, Buffer) && unk_193BF80 && *(_DWORD *)unk_193BF80 )
  {
    v4 = *(_DWORD *)(v3 + 20);
    v5 = *(__int16 *)(v4 + 18);
    if ( v5 > 0 )
    {
      v6 = (_WORD *)(*(_DWORD *)(v4 + 8) + 2 + v4);
      do
      {
        *v6 = 0;
        v6 += 3;
        --v5;
      }
      while ( v5 );
    }
    *(float *)(v3 + 164) = 0.0;
    *(float *)(v3 + 148) = 0.0;
    *(_DWORD *)(v3 + 16) |= 6u;
    return v3;
  }
  if ( !v3 )
    return v3;
  sub_928000(v3);
  return 0;
}
