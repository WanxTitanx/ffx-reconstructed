// Function: sub_932320
// Address: 0x932320
int sub_932320()
{
  *(_DWORD *)(unk_193C0F0 + 2092) = 0;
  *(_DWORD *)(unk_193C0F0 + 2088) = 0;
  *(_DWORD *)(unk_193C0F0 + 2084) = 0;
  memset((void *)(unk_193C0F0 + 2160), 255, 0x40u);
  *(_DWORD *)(unk_193C0F0 + 2224) = 0;
  *(_DWORD *)(unk_193C0F0 + 2244) = 0;
  if ( sub_92E620() )
    sub_9323B0();
  else
    sub_932570();
  return sub_932470();
}
