// Function: sub_93E370
// Address: 0x93e370
int __cdecl sub_93E370(int a1, int n32771, unsigned int n0x1F)
{
  _DWORD *v3; // ebx
  int v4; // eax
  int v5; // eax
  const char *NameFromModelSlot; // eax
  int i; // esi
  int v9; // [esp+0h] [ebp-94h]
  int v10; // [esp+Ch] [ebp-88h]
  char Buffer[128]; // [esp+10h] [ebp-84h] BYREF

  v3 = (_DWORD *)sub_84AEC0(a1);
  if ( n32771 == 32769 )
  {
    v3 = (_DWORD *)FFX_Memory_Alloc(8u, v9);
    *v3 = unk_193C148;
    sub_84B560(a1, v3);
    NameFromModelSlot = (const char *)FFX_MagicPath_GetNameFromModelSlot(unk_193C148);
    sprintf(Buffer, "TEX ANIM (%s)", NameFromModelSlot);
    sub_84B6A0(a1);
    v10 = sub_82B9E0(*v3);
    nullsub_34();
    for ( i = 0; i < 32; ++i )
    {
      sprintf(Buffer, "%d", i);
      sub_84A470(a1, i, Buffer, 20 * (i & 7), 20 * ((unsigned int)i >> 3) + 4, 17, 14);
      sub_849380(a1, i, 1);
    }
    sub_8493E0(a1, n0x1F, 1);
    v3[1] = 0;
    sub_77EA30(v10, 4, 0, 0, 0);
  }
  else
  {
    if ( n32771 == 32771 )
    {
      FFX_Memory_Delete((int)v3, v9);
      return 0;
    }
    if ( n32771 == 32775 && n0x1F <= 0x1F )
    {
      v4 = sub_82B9E0(*v3);
      sub_77EA30(v4, 4, n0x1F, 0, 0);
      v5 = v3[1];
      if ( v5 >= 0 )
        sub_8493E0(a1, v5, 0);
      sub_8493E0(a1, n0x1F, 1);
      v3[1] = n0x1F;
    }
  }
  if ( v3 && (int)sub_826230(*v3) < 0 )
    sub_84AB80(a1);
  return 0;
}
