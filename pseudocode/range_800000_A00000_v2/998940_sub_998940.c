// Function: sub_998940
// Address: 0x998940
int __thiscall sub_998940(char *this, int a2, _DWORD *a3)
{
  char *v3; // edx
  int result; // eax

  v3 = this + 16 * a2 + 64;
  *a3 = *(_DWORD *)v3;
  a3[1] = *((_DWORD *)v3 + 1);
  a3[2] = *((_DWORD *)v3 + 2);
  result = *((_DWORD *)v3 + 3);
  a3[3] = result;
  return result;
}
