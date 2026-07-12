// Function: sub_A1C940
// Address: 0xa1c940
// Size: 0x26
// Prototype: 

int __stdcall sub_A1C940(int a1, int a2)
{
  int v2; // eax

  if ( a2 )
    v2 = a2 + 4;
  else
    v2 = 0;
  return PhyreLua_PushPhyreObject(a1, v2, (int)&unk_19446D8);
}

