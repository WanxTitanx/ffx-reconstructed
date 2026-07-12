// Function: ?InitializeTicket@ClaimTicket@VirtualProcessor@details@Concurrency@@AAEXW4AvailabilityType@234@PAV234@@Z_1
// Address: 0xa2a7f0
// Size: 0x12
// Prototype: 

int __thiscall Concurrency::details::VirtualProcessor::ClaimTicket::InitializeTicket(_DWORD *this, int a2, int a3)
{
  *this = a2;
  *(this + 1) = a3;
  return a3;
}

