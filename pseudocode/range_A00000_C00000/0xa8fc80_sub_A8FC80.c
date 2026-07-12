// Function: sub_A8FC80
// Address: 0xa8fc80
// Size: 0xfa
// Prototype: int(void)

int __fastcall sub_A8FC80(int *a1, int a2)
{
  int *v4; // ebx
  int v6; // eax
  int n0x2000; // edx

  v4 = (int *)a1[7];
  if ( !v4 )
    return -129;
  v6 = sub_42EB10(a2, 32);
  *a1 = v6;
  if ( v6 )
    return -134;
  a1[1] = sub_42EB10(a2, 8);
  a1[2] = sub_42EB10(a2, 32);
  a1[3] = sub_42EB10(a2, 32);
  a1[4] = sub_42EB10(a2, 32);
  a1[5] = sub_42EB10(a2, 32);
  *v4 = 1 << sub_42EB10(a2, 4);
  n0x2000 = 1 << sub_42EB10(a2, 4);
  v4[1] = n0x2000;
  if ( a1[2] >= 1 && a1[1] >= 1 && *v4 >= 64 && n0x2000 >= *v4 && n0x2000 <= 0x2000 )
    return 23;
  sub_A8FD80(a1);
  return -133;
}

