// Function: sub_AF7250
// Address: 0xaf7250
// Size: 0x31
// Prototype: 

int sub_AF7250()
{
  if ( !sub_A2EBF0("Button_MiddleMB") )
  {
    dword_C6C3E4 = dword_1A853CC;
    dword_1A853CC = &off_C6C3DC;
  }
  return atexit(sub_B0A550);
}

