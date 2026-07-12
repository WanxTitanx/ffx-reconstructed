// Function: sub_A64D90
// Address: 0xa64d90
// Size: 0x49
// Prototype: 

int __cdecl sub_A64D90(__int16 *a1)
{
  int v1; // ecx
  char *v3; // [esp-4h] [ebp-4h]

  v1 = a1[1];
  v3 = (char *)a1 + v1;
  if ( *a1 >= 0 )
    return nullsub_93("%7x u_task_%1d(%7x)", a1, (v1 >> 12) & 3, v3);
  else
    return nullsub_93("%7x u_taskp_%1d(%7x)", a1, (v1 >> 12) & 3, v3);
}

