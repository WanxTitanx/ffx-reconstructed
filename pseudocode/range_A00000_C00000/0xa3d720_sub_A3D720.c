// Function: sub_A3D720
// Address: 0xa3d720
// Size: 0x58

int __thiscall sub_A3D720(void *this, int a2)
{
  int v3; // esi
  _DWORD *v4; // eax
  int result; // eax
  _DWORD *v6; // [esp+Ch] [ebp-4h] BYREF

  v6 = 0; /*0xa3d739*/
  v3 = sub_5B5AE0(sub_A3D6D0, 8, &v6); /*0xa3d745*/
  if ( !v3 ) /*0xa3d749*/
  {
    v4 = v6; /*0xa3d74b*/
    *v6 = this; /*0xa3d74e*/
    v4[1] = sub_A3D780; /*0xa3d750*/
  }
  result = (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 8))(a2); /*0xa3d75b*/
  if ( !result ) /*0xa3d760*/
  {
    result = FFX_Ps3Tex_ListClear(a2); /*0xa3d764*/
    if ( !result ) /*0xa3d76b*/
      return v3; /*0xa3d76d*/
  }
  return result; /*0xa3d76f*/
}