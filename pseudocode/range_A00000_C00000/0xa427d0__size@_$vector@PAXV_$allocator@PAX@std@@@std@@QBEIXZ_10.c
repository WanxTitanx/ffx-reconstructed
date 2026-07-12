// Function: ?size@?$vector@PAXV?$allocator@PAX@std@@@std@@QBEIXZ_10
// Address: 0xa427d0
// Size: 0x9

int __thiscall std::vector<void *>::size(_DWORD *this)
{
  return (*(this + 1) - *this) >> 2; /*0xa427d8*/
}