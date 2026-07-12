// Function: sub_A0E620
// Address: 0xa0e620
// Size: 0x1e5

int __thiscall sub_A0E620(_DWORD *this, int a2)
{
  int n3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edi
  _BYTE *v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // esi
  _BYTE v17[16]; // [esp+10h] [ebp-4Ch] BYREF
  _BYTE v18[16]; // [esp+20h] [ebp-3Ch] BYREF
  _BYTE v19[16]; // [esp+30h] [ebp-2Ch] BYREF
  _BYTE v20[16]; // [esp+40h] [ebp-1Ch] BYREF
  int n2; // [esp+58h] [ebp-4h]

  n3 = *(this + 4021); /*0xa0e64a*/
  if ( n3 == 3 ) /*0xa0e653*/
  {
    sub_5B3760(*(this + 4078), 0); /*0xa0e664*/
    v4 = *(this + 4021); /*0xa0e669*/
    n2 = 0; /*0xa0e66f*/
    v5 = v4 - 1; /*0xa0e676*/
    if ( v5 ) /*0xa0e677*/
    {
      v6 = v5 - 1; /*0xa0e679*/
      if ( v6 ) /*0xa0e67a*/
      {
        if ( v6 == 1 ) /*0xa0e67d*/
          v7 = *(this + 4079); /*0xa0e683*/
        else
          v7 = 0; /*0xa0e67f*/
      }
      else
      {
        v7 = *(this + 4073); /*0xa0e68... [2796 chars total]