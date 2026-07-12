// Function: sub_930290
// Address: 0x930290
int __cdecl sub_930290(char *a1)
{
  int result; // eax

  sub_92ED10(a1);
  result = sub_92ED10(a1 + 188);
  *((_DWORD *)a1 + 2) = a1 + 188;
  *((_DWORD *)a1 + 46) = 0;
  *((_DWORD *)a1 + 93) = 0xFFFF;
  *((_DWORD *)a1 + 48) = a1;
  *((_DWORD *)a1 + 94) = 0;
  return result;
}
