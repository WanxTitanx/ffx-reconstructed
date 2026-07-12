// Function: ?size@?$vector@PAXV?$allocator@PAX@std@@@std@@QBEIXZ_9
// Address: 0xa41bf0
// Size: 0xa
// Prototype: 

int __thiscall std::vector<void *>::size(_DWORD *this)
{
  return (*(this + 2) - *(this + 1)) >> 2;
}

