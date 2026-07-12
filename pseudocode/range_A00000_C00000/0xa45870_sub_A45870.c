// Function: sub_A45870
// Address: 0xa45870
// Size: 0x2f
// Prototype: 

int __cdecl sub_A45870(int a1)
{
  if ( FFX_Party_IsMemberActive(a1) )
    return *(unsigned __int16 *)(unk_2305834 + 80 * a1 + 69836);
  else
    return -1;
}

