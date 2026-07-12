// Function: sub_895550
// Address: 0x895550
void sub_895550()
{
  __int16 v0; // cx

  if ( n2_4 )
  {
    if ( unk_133C8FF )
    {
      v0 = (int)FFX_Menu2D_ScaleY_1080to416(350.0);
      unk_133F742 = v0;
    }
    else
    {
      v0 = unk_133F742;
    }
    if ( MEMORY[0x133F754] >= 1.0 )
      sub_901490(MEMORY[0x133F754], unk_133F740 + 15, v0 - 20, -2139062144);
    else
      sub_901490(MEMORY[0x133F754], unk_133F740 + 15, v0 - 20, -2147450752);
  }
}
