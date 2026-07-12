// Function: __allshr
// Address: 0xa8d880
// Size: 0x21
// Prototype: 

int __usercall _allshr@<eax>(__int64 a1@<edx:eax>, unsigned __int8 n0x20@<cl>)
{
  if ( n0x20 >= 0x40u )
  {
    LODWORD(a1) = SHIDWORD(a1) >> 31;
  }
  else if ( n0x20 >= 0x20u )
  {
    LODWORD(a1) = SHIDWORD(a1) >> (n0x20 & 0x1F);
  }
  else
  {
    a1 >>= n0x20 & 0x1F;
  }
  return a1;
}

