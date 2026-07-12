// Function: sub_9B2770
// Address: 0x9b2770
int __thiscall sub_9B2770(_DWORD *this, int a2)
{
  int result; // eax

  --*(_DWORD *)(a2 + 32);
  result = *(_DWORD *)(a2 + 4 * *(_DWORD *)(a2 + 32));
  *(this + (*(this + 96))++ + 92) = result;
  return result;
}
