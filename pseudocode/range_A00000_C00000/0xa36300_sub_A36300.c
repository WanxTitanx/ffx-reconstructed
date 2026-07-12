// Function: sub_A36300
// Address: 0xa36300
// Size: 0x5d

int __cdecl sub_A36300(int a1)
{
  int result; // eax
  _DWORD *v2; // esi
  int v3; // ecx
  int v4; // ecx

  result = sub_A3B380(dword_1A858B4 + 164, a1); /*0xa36312*/
  v2 = dword_1A858B4; /*0xa36317*/
  v3 = dword_1A858B4[482]; /*0xa36320*/
  if ( v3 ) /*0xa36328*/
  {
    result = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 8))(dword_1A858B4[482]); /*0xa3632d*/
    v2[482] = 0; /*0xa36330*/
    v2 = dword_1A858B4; /*0xa3633a*/
  }
  v4 = v2[485]; /*0xa36340*/
  if ( v4 ) /*0xa36348*/
  {
    result = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v4 + 8))(v2[485]); /*0xa3634d*/
    v2[485] = 0; /*0xa36350*/
  }
  return result; /*0xa3635a*/
}