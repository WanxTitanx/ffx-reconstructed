// Function: sub_A28BA0
// Address: 0xa28ba0
// Size: 0x54

int __thiscall sub_A28BA0(_DWORD **this, int a2, const char *a3, int a4, int a5, int a6)
{
  int v6; // ebx
  int FastNameUTF8; // eax

  v6 = **(this + 27); /*0xa28ba7*/
  while ( 1 ) /*0xa28bcc*/
  {
    FastNameUTF8 = IggyPlayerCreateFastNameUTF8(v6, a3, strlen(a3)); /*0xa28bcc*/
    if ( FastNameUTF8 ) /*0xa28bd4*/
      break; /*0xa28bd4*/
    Sleep(5u); /*0xa28bd8*/
  }
  return IggyPlayerCallFunctionRS(v6, a2, FastNameUTF8, a4, a5); /*0xa28bed*/
}