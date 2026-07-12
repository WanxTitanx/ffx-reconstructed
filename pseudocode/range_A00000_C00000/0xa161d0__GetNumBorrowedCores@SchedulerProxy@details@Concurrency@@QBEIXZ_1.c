// Function: ?GetNumBorrowedCores@SchedulerProxy@details@Concurrency@@QBEIXZ_1
// Address: 0xa161d0
// Size: 0x7
// Prototype: unsigned int __thiscall(Concurrency::details::SchedulerProxy *__hidden this)

unsigned int __thiscall Concurrency::details::SchedulerProxy::GetNumBorrowedCores(
        Concurrency::details::SchedulerProxy *this)
{
  return *((_DWORD *)this + 42);
}

