// Function: sub_A48280
// Address: 0xa48280
// Size: 0x4d
// Prototype: 

int sub_A48280()
{
  int result; // eax

  if ( !unk_1A8607E )
  {
    *(_DWORD *)(dword_2305834[0] + 71080) = *(_DWORD *)(dword_2305834[0] + 71088);
    *(_DWORD *)(dword_2305834[0] + 71088) = 0;
    *(_DWORD *)(dword_2305834[0] + 71084) = *(_DWORD *)(dword_2305834[0] + 71092);
    result = dword_2305834[0];
    *(_DWORD *)(dword_2305834[0] + 71092) = 0;
  }
  return result;
}

