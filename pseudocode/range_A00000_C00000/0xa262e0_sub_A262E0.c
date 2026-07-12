// Function: sub_A262E0
// Address: 0xa262e0
// Size: 0x194

int __thiscall sub_A262E0(int *this, int a2, int a3, int a4)
{
  _DWORD *v5; // eax
  _DWORD *v6; // edi
  unsigned int v7; // ecx
  int v8; // edi
  int v9; // eax
  unsigned int v10; // edx
  int v11; // ecx
  int v13; // [esp-Ch] [ebp-38h]
  _DWORD v14[8]; // [esp+8h] [ebp-24h] BYREF
  char v15; // [esp+2Bh] [ebp-1h] BYREF

  if ( *(this + 2) != 5 ) /*0xa262ee*/
  {
    v5 = (_DWORD *)sub_42FC60(20, 4); /*0xa262f4*/
    v6 = v5; /*0xa262f9*/
    if ( v5 ) /*0xa26300*/
    {
      *v5 = 0; /*0xa26302*/
      v5[1] = 0; /*0xa26308*/
      v5[2] = 0; /*0xa2630f*/
      v5[3] = 0; /*0xa26316*/
      v5[4] = 0; /*0xa2631d*/
      if ( (_DWORD *)*(this + 3) != v5 && *(this + 2) >= 0 ) /*0xa26335*/
        Phyre_Memory_AlignedFree(*(this + 3)); /*0xa26338*/
      *(this + 3) = (int)v6; /*0xa26340*/
      *(this + 2) = 5; /*0xa26343*/
    }
  }
  v7 = 0; /*0xa2634a*/
  if ( (*(this + 2) & 0x7FFFFFFF) != 0 ) /*0xa26353*/
  {
    do /*0xa26376*/
    {
      ++v7; /*0xa26363*/
      *(_DWORD *... [2413 chars total]