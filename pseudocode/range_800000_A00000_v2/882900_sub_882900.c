// Function: sub_882900
// Address: 0x882900
int __cdecl sub_882900(int a1, int a2)
{
  int v2; // edi
  int v3; // ebx
  int v4; // esi
  int ActorByIndex; // eax
  int v6; // ecx
  int n10; // esi
  float *v8; // edi
  int result; // eax
  int v10; // [esp+18h] [ebp-128h]
  char Buffer_1[256]; // [esp+1Ch] [ebp-124h] BYREF
  char Buffer[32]; // [esp+11Ch] [ebp-24h] BYREF

  v2 = 681 * unk_1328A30;
  v3 = a2 + 2;
  v4 = dword_1328AC0[681 * unk_1328A30 + *((_DWORD *)&unk_1328AB0 + 681 * unk_1328A30)]
     + word_C53414[4 * *((_DWORD *)&unk_1328AB0 + 681 * unk_1328A30)];
  ActorByIndex = FFX_Field_GetActorByIndex(*((_DWORD *)&unk_1328ABC + 681 * unk_1328A30));
  v6 = dword_1328B08[16 * v4 + v2];
  n10 = 0;
  v10 = v6 & 0x80;
  v8 = (float *)(ActorByIndex + 88);
  do
  {
    sub_88FA60(a1 + 4, v3);
    sub_88F0B0(unk_1328A34, 0, "f");
    sprintf(Buffer, "%d", n10);
    sub_88F0B0(unk_1328A34, 0, Buffer);
    sub_88F0B0(unk_1328A34, 0, ":");
    if ( v10 )
    {
      result = sub_87E800(dword_C52714[n10]);
    }
    else
    {
      sprintf(Buffer_1, "%f\n", *v8);
      result = sub_88F0B0(0, 0, Buffer_1);
    }
    ++n10;
    ++v8;
    v3 += 13;
  }
  while ( n10 < 10 );
  return result;
}
