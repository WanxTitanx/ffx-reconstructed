// Function: sub_A461B0
// Address: 0xa461b0
// Size: 0x140

int __cdecl sub_A461B0(int a1, int a2)
{
  int v2; // ecx
  char n2; // al
  unsigned __int8 v4; // bl
  int v5; // edx
  unsigned __int8 n4; // bl
  int result; // eax
  int v8; // [esp+4h] [ebp-4h]

  v2 = unk_2305834; /*0xa461b4*/
  n2 = *(_BYTE *)(unk_2305834 + 71102); /*0xa461bb*/
  if ( n2 == 1 ) /*0xa461c3*/
  {
    v4 = *(_BYTE *)(unk_2305834 + 71103); /*0xa461c5*/
    v5 = 91 * v4 / 4 - 80; /*0xa461da*/
  }
  else
  {
    if ( n2 != 2 ) /*0xa461e1*/
    {
LABEL_7:
      result = sub_8EFD90( /*0xa46221*/
                 unk_230FD2C + 16,
                 *(unsigned __int8 *)(v2 + 71100),
                 a1,
                 a2,
                 128,
                 128,
                 128,
                 *(unsigned __int8 *)(v2 + 71097),
                 6);
      unk_230FD2C = result; /*0xa46259*/
      return result; /*0xa46262*/
    }
    v4 = *(_BYTE *)(unk_2305834 + 71103); /*0xa461e3*/
    v5 = 80 - 91 * v4 / 4; /*0xa461fd*/
  }
  n4 = v4 + 1; /*0xa461ff*/
  v8 = v... [1918 chars total]