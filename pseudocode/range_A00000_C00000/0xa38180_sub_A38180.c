// Function: sub_A38180
// Address: 0xa38180
// Size: 0x16b
// Prototype: 

BOOL __cdecl sub_A38180(int a1, int n9_1, void *a3)
{
  int n9; // esi
  _DWORD *v4; // ecx
  BOOL result; // eax
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // edx
  _WORD v10[24]; // [esp+8h] [ebp-30h] BYREF

  memset(v10, 0, sizeof(v10));
  n9 = 9;
  if ( a1 )
    n9 = n9_1;
  if ( dword_C6D448[2 * a1] == n9 && *(&off_C6D44C + 2 * a1) == a3 )
    return 1;
  v4 = dword_1A858B4;
  dword_C6D448[2 * a1] = n9;
  *(&off_C6D44C + 2 * a1) = a3;
  if ( !v4 )
    return 1;
  switch ( a1 )
  {
    case 0:
      sub_A36300(v10);
      sub_A39BC0(dword_1A858B4 + 164, n9, a3);
      return 1;
    case 1:
      v6 = v4[684];
      if ( v6 )
      {
        sub_A3B380(v6, v10);
        IggyGDrawFree(dword_1A858B4[684]);
      }
      v7 = sub_A3BCD0(1);
      dword_1A858B4[684] = v7;
      result = v7 != 0;
      break;
    case 2:
      v8 = v4[685];
      if ( v8 )
      {
        sub_A3B380(v8, v10);
        IggyGDrawFree(dword_1A858B4[685]);
      }
      v9 = sub_A3BCD0(2);
      dword_1A858B4[685] = v9;
      result = v9 != 0;
      break;
    case 3:
      sub_A3D280();
      sub_A34910(dword_1A858B4 + 614);
      sub_A34910(dword_1A858B4 + 618);
      result = sub_A34B10((unsigned int)a3);
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

