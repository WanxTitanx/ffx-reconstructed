// Function: _beginthreadex
// Address: 0xa8d8a2
// Size: 0x6
// Prototype: uintptr_t __cdecl(void *Security, unsigned int StackSize, _beginthreadex_proc_type StartAddress, void *ArgList, unsigned int InitFlag, unsigned int *ThrdAddr)

// attributes: thunk
uintptr_t __cdecl beginthreadex(
        void *Security,
        unsigned int StackSize,
        _beginthreadex_proc_type StartAddress,
        void *ArgList,
        unsigned int InitFlag,
        unsigned int *ThrdAddr)
{
  return _beginthreadex(Security, StackSize, StartAddress, ArgList, InitFlag, ThrdAddr);
}

