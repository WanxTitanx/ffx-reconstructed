// Function: sub_A48F20
// Address: 0xa48f20
// Size: 0x2b
// Prototype: 

int __cdecl sub_A48F20(int a1)
{
  int result; // eax

  result = unk_1A86108 + 832 * a1;
  if ( !*(_BYTE *)(result + 35) || *(_DWORD *)(result + 52) )
  {
    *(_BYTE *)(result + 41) = 0;
    *(_DWORD *)(result + 52) = sub_A5A270;
  }
  return result;
}

