// Function: sub_AF7290
// Address: 0xaf7290
// Size: 0x31
// Prototype: 

int sub_AF7290()
{
  if ( !sub_A2EBF0("Button_RightMB") )
  {
    dword_C6C404 = dword_1A853CC;
    dword_1A853CC = &off_C6C3FC;
  }
  return atexit(sub_B0A570);
}

