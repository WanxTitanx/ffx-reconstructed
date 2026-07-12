// Function: sub_A1C910
// Address: 0xa1c910
// Size: 0x26
// Prototype: 

int __stdcall sub_A1C910(int a1, int a2)
{
  int v2; // eax

  if ( a2 )
    v2 = a2 + 4;
  else
    v2 = 0;
  return PhyreLua_PushPhyreObject(a1, v2, (int)&unk_1944770);
}

