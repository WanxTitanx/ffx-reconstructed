// Function: sub_9204B0
// Address: 0x9204b0
int __cdecl sub_9204B0(int a1, _DWORD *a2, _DWORD *a3, int a4, float a5)
{
  int v5; // eax
  float v7; // [esp+Ch] [ebp-28h]
  int v8[4]; // [esp+10h] [ebp-24h] BYREF
  int v9[4]; // [esp+20h] [ebp-14h] BYREF

  if ( unk_193BF80 && *(_DWORD *)unk_193BF80 )
    v5 = *(_DWORD *)(*(_DWORD *)unk_193BF80 + 8);
  else
    v5 = 0;
  v7 = *(float *)(v5 + 244);
  sub_9200A0(v8, a2, v7);
  sub_9200A0(v9, a3, v7);
  return sub_7C1B70(a1, (int)v8, (int)v9, a4, a5);
}
