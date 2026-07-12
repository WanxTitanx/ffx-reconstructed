// Function: sub_AF6DD0
// Address: 0xaf6dd0
// Size: 0x31
// Prototype: 

int sub_AF6DD0()
{
  if ( !sub_A2E780("Key_Right_Alt") )
  {
    dword_C6BCBC = dword_1A85390;
    dword_1A85390 = &off_C6BCB4;
  }
  return atexit(sub_B0A300);
}

