// Function: sub_A54560
// Address: 0xa54560
// Size: 0x3b
// Prototype: 

int sub_A54560()
{
  int result; // eax

  result = dword_2305834[0];
  if ( !*(_BYTE *)(dword_2305834[0] + 71098) )
  {
    if ( *(_BYTE *)(dword_2305834[0] + 71099) )
      sub_A54660();
    else
      sub_A545A0();
    result = dword_2305834[0];
    *(_BYTE *)(dword_2305834[0] + 71099) = 0;
  }
  return result;
}

