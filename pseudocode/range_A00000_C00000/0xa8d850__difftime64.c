// Function: _difftime64
// Address: 0xa8d850
// Size: 0x6
// Prototype: double __cdecl(__time64_t Time1, __time64_t Time2)

// attributes: thunk
double __cdecl difftime64(__time64_t Time1, __time64_t Time2)
{
  return _difftime64(Time1, Time2);
}

