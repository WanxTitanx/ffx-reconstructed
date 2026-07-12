// Function: sub_A3E600
// Address: 0xa3e600
// Size: 0xc7
// Prototype: 

int __stdcall sub_A3E600(int a1, int a2, int n400, const char *a4)
{
  int n3; // edi
  const char *Error:_; // eax
  unsigned int v6; // kr00_4
  char Buffer[16384]; // [esp+Ch] [ebp-4004h] BYREF

  n3 = 1;
  if ( n400 >= 400 )
  {
    Error:_ = "Error: ";
    n3 = 3;
  }
  else
  {
    Error:_ = "Warning: ";
  }
  sprintf_s(Buffer, 0x4000u, "Iggy: %s", Error:_);
  v6 = strlen(Buffer);
  sprintf_s(&Buffer[v6], -4 - (v6 - 16388), "%s", a4);
  *(_WORD *)&Buffer[v6 + strlen(&Buffer[v6])] = 10;
  return sub_435490(n3, (int)Buffer);
}

