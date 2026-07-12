// Function: sub_A1C4E0
// Address: 0xa1c4e0
// Size: 0x26
// Prototype: 

int __stdcall sub_A1C4E0(int a1, int a2)
{
  int v2; // eax

  if ( a2 )
    v2 = a2 + 4;
  else
    v2 = 0;
  return PhyreLua_PushPhyreObject(a1, v2, (int)&unk_1943978);
}

