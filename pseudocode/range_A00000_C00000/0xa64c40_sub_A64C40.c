// Function: sub_A64C40
// Address: 0xa64c40
// Size: 0x57
// Prototype: 

int __cdecl sub_A64C40(int a1)
{
  int v1; // eax
  char Buffer[256]; // [esp+4h] [ebp-104h] BYREF

  v1 = sprintf(Buffer, "%07x u_v(", a1);
  sub_A65570(&Buffer[v1], a1);
  return nullsub_93(Buffer);
}

