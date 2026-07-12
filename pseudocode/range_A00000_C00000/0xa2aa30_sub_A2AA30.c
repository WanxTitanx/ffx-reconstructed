// Function: sub_A2AA30
// Address: 0xa2aa30
// Size: 0x8b
// Prototype: int __stdcall(char *Str2)

int __thiscall sub_A2AA30(int this, char *Str2)
{
  int result; // eax
  unsigned int i; // esi
  const char *Str1; // edx

  if ( !Str2 ) /*0xa2aa3c*/
    return 1; /*0xa2aa44*/
  i = strlen(Str2); /*0xa2aa48*/
  Str1 = *(const char **)(this + 352); /*0xa2aa57*/
  if ( !Str1 || i > (*(_DWORD *)(this + 348) & 0x7FFFFFFFu) - 1 ) /*0xa2aa74*/
  {
    result = sub_A2A110(this, i); /*0xa2aa90*/
    if ( result ) /*0xa2aa97*/
      return result; /*0xa2aa97*/
    goto LABEL_8; /*0xa2aa97*/
  }
  result = strncmp(Str1, Str2, i + 1); /*0xa2aa79*/
  if ( result ) /*0xa2aa84*/
  {
LABEL_8:
    memcpy(*(void **)(this + 352), Str2, i + 1); /*0xa2aa99*/
    return sub_A29770(this, i); /*0xa2aaaf*/
  }
  return result; /*0xa2aa3e*/
}