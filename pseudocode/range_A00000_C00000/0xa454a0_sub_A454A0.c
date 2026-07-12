// Function: sub_A454A0
// Address: 0xa454a0
// Size: 0x51
// Prototype: 

int sub_A454A0()
{
  char *EntryByIdRange; // eax
  int v1; // edi
  char *EntryByIdRange_1; // esi
  char v3; // al
  int v5; // [esp+8h] [ebp-4h] BYREF

  EntryByIdRange = FFX_Table_GetEntryByIdRange(
                     *(unsigned __int16 *)(unk_2305834 + 40 * *(unsigned __int16 *)(unk_2305834 + 70396) + 2062),
                     (__int16 *)unk_1A860E0,
                     &v5);
  v1 = v5;
  EntryByIdRange_1 = EntryByIdRange;
  v3 = sub_7852B0();
  return sub_A59350(v1 + *(unsigned __int16 *)&EntryByIdRange_1[4 * (v3 & 1) + 8]);
}

