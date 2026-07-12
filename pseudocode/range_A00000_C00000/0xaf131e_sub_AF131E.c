// Function: sub_AF131E
// Address: 0xaf131e
// Size: 0x28
// Prototype: 

int sub_AF131E()
{
  HANDLE ProcessHeap; // eax

  ProcessHeap = GetProcessHeap();
  unk_193FCFC = &off_B702A0;
  ::ProcessHeap = ProcessHeap;
  unk_193FD04 = 0;
  return atexit(sub_B07DC4);
}

