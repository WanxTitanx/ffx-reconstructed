// Function: sub_A2AD80
// Address: 0xa2ad80
// Size: 0x36

int __thiscall sub_A2AD80(const char **this, unsigned int i)
{
  int result; // eax

  result = sub_A2A110((int)this, i); /*0xa2ad89*/
  if ( !result ) /*0xa2ad90*/
    return sub_A29770((int)this, strlen(*(this + 88))); /*0xa2adac*/
  return result; /*0xa2adb1*/
}