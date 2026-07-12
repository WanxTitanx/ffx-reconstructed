// Function: sub_A69290
// Address: 0xa69290
// Size: 0x66

int __cdecl sub_A69290(_DWORD *a1, int a2)
{
  _DWORD *v2; // esi
  int v3; // edi
  int result; // eax
  int v5; // ecx
  int v6; // edx

  v2 = a1; /*0xa69294*/
  v3 = sub_A698C0(a1); /*0xa6929e*/
  if ( !v3 ) /*0xa692a5*/
  {
    nullsub_34(); /*0xa692ac*/
    nullsub_35(1, "op_md_copy error !!!\t\tomd size zero byte\n"); /*0xa692b3*/
  }
  result = v3; /*0xa692bd*/
  v5 = v3 / 16; /*0xa692c4*/
  if ( v3 / 16 > 0 ) /*0xa692c9*/
  {
    v6 = a2 - (_DWORD)a1; /*0xa692ce*/
    do /*0xa692f0*/
    {
      *(_DWORD *)((char *)v2 + v6) = *v2; /*0xa692d2*/
      *(_DWORD *)((char *)v2 + v6 + 4) = v2[1]; /*0xa692d8*/
      *(_DWORD *)((char *)v2 + v6 + 8) = v2[2]; /*0xa692df*/
      result = v2[3]; /*0xa692e3*/
      --v5; /*0xa692e6*/
      *(_DWORD *)((char *)v2 + v6 + 12) = result; /*0xa692e7*/
      v2 += 4; /*0xa692eb*/
    }
    while ( v5 > 0 ); /*0xa692f0*/
  }
  return result; /*0xa692f2*/
}