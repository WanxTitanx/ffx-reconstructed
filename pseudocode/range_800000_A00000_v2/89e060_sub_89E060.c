// Function: sub_89E060
// Address: 0x89e060
unsigned __int8 __usercall sub_89E060@<al>(int a1@<ebp>, unsigned __int8 *a2, __int16 a3, __int16 a4, char a5)
{
  unsigned __int8 *v5; // esi
  unsigned __int8 n0x30; // al
  double v7; // st7
  double v8; // st6
  __int16 v9; // ax
  int v10; // ecx
  double v11; // st5
  int v12; // eax
  int v13; // [esp-64h] [ebp-70h]
  float v14[16]; // [esp-60h] [ebp-6Ch] BYREF
  _DWORD v15[6]; // [esp-20h] [ebp-2Ch] BYREF
  int v16; // [esp-8h] [ebp-14h]
  int v17; // [esp+0h] [ebp-Ch]
  void *v18; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v17 = a1;
  v18 = retaddr;
  v5 = a2;
  memset(v14, 0, sizeof(v14));
  v16 = 0;
  memset(&v15[3], 0, 12);
  *(float *)&v15[1] = (float)a3;
  v15[0] = -2139062144;
  HIBYTE(v16) = a5;
  *(float *)&v15[2] = (float)a4;
  sub_9046E0();
  n0x30 = *a2;
  if ( *a2 )
  {
    v7 = 8.0;
    v8 = 8.0;
    do
    {
      if ( n0x30 >= 0x30u )
        v9 = n0x30 - 48;
      else
        v9 = v5[1] + 160;
      HIWORD(v14[0]) = 20;
      v10 = v9;
      v11 = (double)(unsigned __int8)byte_C58F03[4 * v9];
      v13 = (unsigned __int8)byte_C58F00[4 * v9];
      v12 = (unsigned __int8)byte_C58F01[4 * v9];
      v14[7] = v11;
      LOBYTE(v10) = byte_C58F02[4 * v10];
      v14[8] = v7;
      v14[2] = (float)v13;
      HIWORD(v14[9]) = (unsigned __int8)v10;
      v14[3] = (float)v12;
      LOWORD(v14[1]) = (v10 & 8) != 0;
      v14[4] = v14[2] + v14[7];
      v14[5] = v8 + v14[3];
      sub_8FC770(v15, v14);
      v7 = 8.0;
      v8 = 8.0;
      v5 = (unsigned __int8 *)sub_8DFD70(v5);
      n0x30 = *v5;
    }
    while ( *v5 );
  }
  return n0x30;
}
