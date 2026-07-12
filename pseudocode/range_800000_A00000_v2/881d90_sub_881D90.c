// Function: sub_881D90
// Address: 0x881d90
int __cdecl sub_881D90(int a1, int a2)
{
  int v2; // ebx
  int v3; // ecx
  int v4; // edi
  int n30; // eax
  int n1023; // esi
  int n1023_1; // [esp+Ch] [ebp-30h]
  int n30_1; // [esp+10h] [ebp-2Ch]
  char Buffer[32]; // [esp+18h] [ebp-24h] BYREF

  v2 = a2 + 2;
  sub_86AF30(0);
  n30_1 = 0;
  v3 = (dword_1328AC0[unk_1328AB0] + word_C53414[4 * unk_1328AB0]) << 6;
  v4 = a2 + 14;
  n30 = *(_DWORD *)((char *)&unk_1328ADC + v3);
  n1023 = *(_DWORD *)((char *)&unk_1328AE8 + v3);
  *(_DWORD *)((char *)&unk_1328B04 + v3) = 1023;
  n1023_1 = n30;
  do
  {
    if ( n1023 > 1023 )
      break;
    sub_88FA60(a1 + 4, v2);
    sprintf(Buffer, "Help %04d ", n1023);
    sub_88F430(unk_1328A34, 0, Buffer);
    sub_88FA60(a1 + 68, v2);
    if ( sub_86B970(n1023) )
      sub_88F430(unk_1328A34, 0, "   On");
    else
      sub_88F430(unk_1328A34, 0, "   Off");
    if ( n1023 == n1023_1 )
      sub_88FAA0(2, 0, a1 + 4, v4, a1 + 360, v4);
    n30 = n30_1 + 1;
    ++n1023;
    v2 += 13;
    v4 += 13;
    n30_1 = n30;
  }
  while ( n30 < 30 );
  return n30;
}
