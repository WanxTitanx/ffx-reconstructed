// Function: sub_A27BD0
// Address: 0xa27bd0
// Size: 0x6f
// Prototype: 

unsigned __int64 __thiscall sub_A27BD0(int this)
{
  double v1; // st7

  v1 = (double)(unsigned int)(*(_DWORD *)(this + 256) + 1) * *(double *)(this + 264);
  if ( v1 < 9.223372036854776e18 )
    return (unsigned __int64)v1;
  v1 = v1 - 9.223372036854776e18;
  if ( v1 >= 9.223372036854776e18 )
    return (unsigned __int64)v1;
  else
    return (unsigned __int64)v1 + 0x8000000000000000uLL;
}

