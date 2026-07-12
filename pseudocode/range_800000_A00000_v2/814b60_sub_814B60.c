// Function: sub_814B60
// Address: 0x814b60
_WORD *__cdecl sub_814B60(int a1, _WORD *a2)
{
  _WORD *v2; // ebx
  int v3; // eax
  int v4; // edi
  int i_1; // ebx
  int i; // esi
  int v7; // edi
  int j_1; // ebx
  int j; // esi
  int v10; // edi
  int v12; // [esp+4h] [ebp-224h]
  int v13; // [esp+8h] [ebp-220h] BYREF
  int v14; // [esp+Ch] [ebp-21Ch] BYREF
  _WORD *v15; // [esp+10h] [ebp-218h]
  int v16; // [esp+14h] [ebp-214h] BYREF
  int v17; // [esp+18h] [ebp-210h]
  int v18; // [esp+1Ch] [ebp-20Ch]
  int v19; // [esp+20h] [ebp-208h]
  char Buffer[512]; // [esp+24h] [ebp-204h] BYREF

  v2 = a2;
  v15 = a2;
  if ( a2[1] )
    return a2;
  v18 = (__int16)a2[2];
  v3 = sub_7FE9C0(v18);
  if ( v3 >= 0 )
  {
    v4 = *((_DWORD *)&unk_12A2280 + 8 * v3);
    v19 = v4;
    if ( v4 )
    {
      v17 = (__int16)a2[4];
      nullsub_34();
      i_1 = sub_83CDB0(v4);
      nullsub_34();
      for ( i = 0; i < i_1; ++i )
      {
        v12 = sub_83CD50(v4, i, &v14, &v13);
        nullsub_34();
        sprintf(Buffer, "host0:/home/yonishi/ffx/dat/t_%4x_%d.txc", v18, i);
        v7 = sub_62FBE0(Buffer, 2);
        if ( v7 )
        {
          sub_62FF70(v7, v12);
          FFX_FileIO_IopDevice_Close(v7);
        }
        v4 = v19;
      }
      j_1 = sub_83CD90(v4);
      nullsub_34();
      for ( j = 0; j < j_1; ++j )
      {
        v17 = sub_83CD20(v4, j, &v16);
        nullsub_34();
        sprintf(Buffer, "host0:/home/yonishi/ffx/dat/c_%4x_%d.clt", v18, j);
        v10 = sub_62FBE0(Buffer, 2);
        if ( v10 )
        {
          sub_62FF70(v10, v17);
          FFX_FileIO_IopDevice_Close(v10);
        }
        v4 = v19;
      }
      v2 = v15;
    }
  }
  return v2 + 5;
}
