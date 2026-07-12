// Function: sub_A93550
// Address: 0xa93550
// Size: 0x52
// Prototype: int __thiscall(void *Block)

void __thiscall sub_A93550(void **Block)
{
  if ( *(Block + 9) )
  {
    if ( *(Block + 8) )
      free_1(*(Block + 8));
    if ( *(Block + 2) )
      free_1(*(Block + 2));
    *(_QWORD *)Block = 0;
    *((_QWORD *)Block + 1) = 0;
    *((_QWORD *)Block + 2) = 0;
    *((_QWORD *)Block + 3) = 0;
    *((_QWORD *)Block + 4) = 0;
    free_1(Block);
  }
}

