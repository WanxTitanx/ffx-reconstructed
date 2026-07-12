// Function: sub_A28A40
// Address: 0xa28a40
// Size: 0x48
// Prototype: int __thiscall(_DWORD)

int __usercall sub_A28A40@<eax>(_DWORD *a1@<ecx>, int a2@<edi>)
{
  bool v3; // zf
  int result; // eax
  int v5; // edi

  v3 = a1[27] == 0; /*0xa28a43*/
  *a1 = &IggyMenu::`vftable'; /*0xa28a47*/
  if ( !v3 ) /*0xa28a4d*/
  {
    sub_A26C50(unk_1984C6C, (int)a1); /*0xa28a57*/
    result = sub_A3D720(a1[26]); /*0xa28a62*/
    v5 = a1[27]; /*0xa28a67*/
    if ( v5 ) /*0xa28a6c*/
    {
      sub_A3D4D0(a2); /*0xa28a70*/
      result = Phyre_Memory_AlignedFree(v5); /*0xa28a76*/
    }
    a1[27] = 0; /*0xa28a7e*/
  }
  return result; /*0xa28a86*/
}