// Function: sub_A284A0
// Address: 0xa284a0
// Size: 0x3c7

char __thiscall sub_A284A0(int this, int a2, int a3, int a4)
{
  int v5; // eax
  bool v6; // zf
  char *Src; // [esp+10h] [ebp-7Ch]
  char *Srca; // [esp+10h] [ebp-7Ch]
  _BYTE v10[4]; // [esp+18h] [ebp-74h] BYREF
  void *v11; // [esp+1Ch] [ebp-70h]
  size_t Size; // [esp+20h] [ebp-6Ch]
  int v13; // [esp+88h] [ebp-4h]

  if ( *(_DWORD *)(this + 228) != 1 ) /*0xa284e0*/
    return 0; /*0xa284e0*/
  if ( !*(_BYTE *)(this + 680) ) /*0xa284ed*/
    goto LABEL_5; /*0xa284ed*/
  if ( (unsigned int)sub_A3DDE0(this + 64) < *(_DWORD *)(this + 344) ) /*0xa284fd*/
    return 0; /*0xa28847*/
  *(_BYTE *)(this + 680) = 0; /*0xa28503*/
LABEL_5:
  if ( *(_QWORD *)(a2 + 28) != *(_QWORD *)(this + 332) ) /*0xa28519*/
  {
    if ( sub_596120((_DWORD *)a2) ) /*0xa28526*/
      sub_59CDD0((_DWORD *)a2); /*0xa28531*/
    sub_4C41C0((_DWORD *)a2, *(_DWORD *)(this + 332), *(_DWORD *)(this + 336), (int)&unk_CA2FCC, 0); /*0xa2854b*/
    if ( (*(_DWORD *)(a2 + 36) & 0x7FFFFFFF) != 3 ) /*0xa28558*/
    {
      ... [4512 chars total]