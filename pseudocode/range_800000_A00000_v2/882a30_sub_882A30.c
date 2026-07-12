// Function: sub_882A30
// Address: 0x882a30
int __cdecl sub_882A30(int a1, int a2)
{
  _DWORD *v2; // edi
  int v3; // ebx
  int v4; // esi
  int ActorByIndex; // eax
  int n4; // esi
  _DWORD *v7; // edi
  int result; // eax
  int v9; // [esp+10h] [ebp-28h]
  char Buffer[32]; // [esp+14h] [ebp-24h] BYREF

  v2 = (_DWORD *)((char *)&unk_1328AB0 + 2724 * unk_1328A30);
  v3 = a2 + 2;
  v4 = v2[*v2 + 4] + word_C53414[4 * *v2];
  ActorByIndex = FFX_Field_GetActorByIndex(*((_DWORD *)&unk_1328ABC + 681 * unk_1328A30));
  v9 = v2[16 * v4 + 22];
  n4 = 0;
  v7 = (_DWORD *)(ActorByIndex + 72);
  do
  {
    sub_88FA60(a1 + 4, v3);
    sub_88F0B0(unk_1328A34, 0, &unk_B5D130);
    sprintf(Buffer, "%d", n4);
    sub_88F0B0(unk_1328A34, 0, Buffer);
    sub_88F0B0(unk_1328A34, 0, ":");
    result = sub_87E740(*v7, dword_C52704[n4++], 32, v9);
    v3 += 13;
    ++v7;
  }
  while ( n4 < 4 );
  return result;
}
