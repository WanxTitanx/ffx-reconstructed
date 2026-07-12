// Function: sub_882230
// Address: 0x882230
int __cdecl sub_882230(int a1, int a2)
{
  int v2; // ecx
  int n0xBF_3; // eax
  unsigned int n0xBF; // esi
  int result; // eax
  int n79; // ecx
  int v7; // edi
  unsigned int v8; // eax
  int v9; // esi
  int v10; // esi
  unsigned __int8 v11; // al
  int n0xBF_2; // [esp+Ch] [ebp-428h]
  unsigned int v13; // [esp+14h] [ebp-420h]
  unsigned int n0xBF_1; // [esp+18h] [ebp-41Ch]
  int n30; // [esp+1Ch] [ebp-418h]
  int v16; // [esp+20h] [ebp-414h]
  int v17; // [esp+24h] [ebp-410h]
  int v18; // [esp+2Ch] [ebp-408h]
  char Buffer[1024]; // [esp+30h] [ebp-404h] BYREF

  v18 = a2 + 2;
  sub_86AF30(0);
  n30 = 0;
  v2 = (dword_1328AC0[unk_1328AB0] + word_C53414[4 * unk_1328AB0]) << 6;
  n0xBF_3 = *(_DWORD *)((char *)&unk_1328ADC + v2);
  n0xBF = *(_DWORD *)((char *)&unk_1328AE8 + v2);
  *(_DWORD *)((char *)&unk_1328B04 + v2) = 271;
  n0xBF_2 = n0xBF_3;
  result = a2 + 14;
  n79 = n0xBF - 192;
  n0xBF_1 = n0xBF;
  v17 = a2 + 14;
  v13 = n0xBF - 192;
  do
  {
    if ( n79 > 79 )
      break;
    if ( n0xBF > 0xBF )
    {
      v7 = n79 / 16 + 3;
      v9 = n79 % 16;
      v16 = 0;
    }
    else
    {
      v7 = (int)n0xBF / 64;
      v8 = n0xBF & 0x80000003;
      v9 = (int)(n0xBF & 0x8000003F) / 4;
      v16 = v8;
    }
    sub_88FA60(a1 + 4, v18);
    sprintf(Buffer, "%02d/%s", v9, (const char *)*(&off_C533E8 + v7));
    sub_88F0D0(0, 0, Buffer);
    sub_88FA60(a1 + 74, v18);
    v10 = *(_DWORD *)FFX_BtlEffect_GetSlotTable((unsigned __int8)byte_C533E0[v7], v9, v16);
    sprintf(Buffer, "/%d:", v16);
    sub_88F0D0(0, 0, Buffer);
    if ( v10 )
    {
      v11 = byte_C53408[v7];
      if ( v11 )
      {
        if ( v10 >= 0 )
          sprintf(Buffer, aSe06d_0, v10, v10 + v11);
        else
          sprintf(Buffer, aSb06d_0, v10 & 0x7FFFFFFF, (v10 & 0x7FFFFFFF) + v11);
      }
      else if ( v10 >= 0 )
      {
        sprintf(Buffer, "se%06d", v10);
      }
      else
      {
        sprintf(Buffer, "sb%06d", v10 & 0x7FFFFFFF);
      }
    }
    else
    {
      sprintf(Buffer, "--------");
    }
    result = sub_88F0D0(0, 0, Buffer);
    if ( n0xBF_1 == n0xBF_2 )
      result = sub_88FAA0(2, 0, a1 + 4, v17, a1 + 360, v17);
    v18 += 13;
    n0xBF = n0xBF_1 + 1;
    n79 = v13 + 1;
    ++n30;
    ++n0xBF_1;
    ++v13;
    v17 += 13;
  }
  while ( n30 < 30 );
  return result;
}
