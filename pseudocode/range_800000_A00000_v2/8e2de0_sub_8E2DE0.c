// Function: sub_8E2DE0
// Address: 0x8e2de0
int sub_8E2DE0()
{
  int result; // eax

  result = unk_23CC120;
  if ( unk_23CC120 )
  {
    if ( *(_DWORD *)(unk_23CC120 + 148) == 2 )
    {
      FFX_BtlHud_NamedAnimStop(1, "scene7");
      result = unk_23CC120;
    }
    *(_BYTE *)(result + 65) = 1;
    unk_23CC120 = 0;
  }
  return result;
}
