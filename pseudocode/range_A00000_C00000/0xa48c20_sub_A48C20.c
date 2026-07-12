// Function: sub_A48C20
// Address: 0xa48c20
// Size: 0x2b
// Prototype: 

int __cdecl sub_A48C20(int a1)
{
  int result; // eax

  result = unk_1A86108 + 832 * a1;
  if ( *(_BYTE *)(result + 35) || *(_DWORD *)(result + 52) )
  {
    *(_BYTE *)(result + 41) = 0;
    *(_DWORD *)(result + 52) = sub_A59800;
  }
  return result;
}

