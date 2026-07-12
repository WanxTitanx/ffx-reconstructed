// Function: longjmp
// Address: 0xa8d7e4
// Size: 0x6
// Prototype: void __cdecl __noreturn(jmp_buf Buf, int Value)

// attributes: thunk
void __cdecl __noreturn longjmp(jmp_buf Buf, int Value)
{
  __imp_longjmp(Buf, Value);
}

