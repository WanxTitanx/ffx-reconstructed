// Function: ?capacity@?$vector@PAXV?$allocator@PAX@std@@@std@@QBEIXZ_5
// Address: 0xa41d40
// Size: 0x9
// Prototype: 

int __thiscall std::vector<void *>::capacity(_DWORD *this)
{
  return (*(this + 2) - *this) >> 2;
}

