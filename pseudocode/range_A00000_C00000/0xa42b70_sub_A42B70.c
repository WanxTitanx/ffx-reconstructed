// Function: sub_A42B70
// Address: 0xa42b70
// Size: 0x29
// Prototype: _DWORD __cdecl(char *Buffer)

void *__cdecl sub_A42B70(char *Buffer)
{
  void *result; // eax
  int savedregs; // [esp+0h] [ebp+0h]

  if ( dword_2310C70 )
    FFX_Memory_Delete(dword_2310C70, savedregs);
  result = sub_A42AB0((int)Buffer, 0);
  dword_2310C70 = (int)result;
  return result;
}

