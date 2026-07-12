// Function: sub_AF6950
// Address: 0xaf6950
// Size: 0x31
// Prototype: 

int sub_AF6950()
{
  if ( !sub_A2E780("Key_Numpad_6") )
  {
    dword_C6BDBC = dword_1A85390;
    dword_1A85390 = &off_C6BDB4;
  }
  return atexit(sub_B0A0C0);
}

