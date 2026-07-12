// Function: sub_93BD10
// Address: 0x93bd10
int __cdecl sub_93BD10(int a1, int n26)
{
  int v2; // esi
  int *v3; // ebx
  int *v4; // esi
  int v5; // edi
  unsigned int v6; // esi
  unsigned int v7; // edi
  int v8; // eax
  void *v9; // eax
  const void *src; // esi
  int v12; // [esp-10h] [ebp-134h]
  int v13; // [esp-Ch] [ebp-130h]
  int v14; // [esp-Ch] [ebp-130h]
  size_t Size; // [esp-8h] [ebp-12Ch]
  int v16; // [esp-4h] [ebp-128h]
  int *i; // [esp+Ch] [ebp-118h]
  int v18; // [esp+10h] [ebp-114h]
  int v19; // [esp+14h] [ebp-110h] BYREF
  _DWORD *v20; // [esp+18h] [ebp-10Ch]
  int v21; // [esp+1Ch] [ebp-108h]
  char Buffer[256]; // [esp+20h] [ebp-104h] BYREF

  v2 = *(_DWORD *)(a1 + 8) + 192 * n26;
  v20 = (_DWORD *)v2;
  v21 = v2 + 144;
  v18 = v2 + 176;
  if ( n26 >= 26 )
    sprintf(Buffer, "host:%s/2d/tex/%s_%c.tm2", unk_193C0F0 + 372, unk_193C0F0 + 636, n26 + 71);
  else
    sprintf(Buffer, "host:%s/2d/tex/%s%c.tm2", unk_193C0F0 + 372, unk_193C0F0 + 636, n26 + 97);
  i = (int *)sub_923B40();
  sub_923800(i, (int)Buffer);
  v3 = (int *)(v2 + 8);
  v13 = v2 + 8;
  v4 = (int *)(v2 + 4);
  sub_9234D0(i, v20 + 3, v20 + 4, v4, v13);
  v5 = *v4;
  v6 = (*v3 + 1) & 0xFFFFFFFE;
  v7 = (v5 + 7) & 0xFFFFFFF8;
  sub_920050(v7, v6, 0, 0, &v19);
  sub_9308D0(v21, 1);
  v8 = sub_92D580();
  *(_DWORD *)(v21 + 16) = v8;
  sub_92D320(v8, 15360, v19, 19, 0, 0, v7, v6, 1);
  v16 = *v3;
  Size = v20[1];
  v14 = v20[4];
  v12 = v20[3];
  v9 = (void *)sub_92D4F0(*(_DWORD *)(v21 + 16), 0);
  sub_923AE0((int)i, v9, v12, v14, Size, v16);
  sub_929950(v18, 1);
  src = (const void *)unknown_libname_741(i[17]);
  qmemcpy((void *)sub_929990(v18, 0), src, 0x400u);
  return sub_923450(i);
}
