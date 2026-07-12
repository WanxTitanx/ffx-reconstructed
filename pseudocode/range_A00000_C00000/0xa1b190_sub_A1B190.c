// Function: sub_A1B190
// Address: 0xa1b190
// Size: 0x25

char __thiscall sub_A1B190(void *this, char **a2, char a3)
{
  char result; // al

  result = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 16))(this); /*0xa1b198*/
  if ( result )
    // "Transparent"
    return a2 != &off_C169D4 ? 0 : a3;
  return result; /*0xa1b19e*/
}