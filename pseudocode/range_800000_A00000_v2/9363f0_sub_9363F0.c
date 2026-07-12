// Function: sub_9363F0
// Address: 0x9363f0
int __cdecl sub_9363F0(int a1, int n32785)
{
  int result; // eax
  int v3; // esi
  float v4; // [esp+8h] [ebp-4h]
  float v5; // [esp+8h] [ebp-4h]

  result = unk_193BF80;
  if ( unk_193BF80 && *(_DWORD *)unk_193BF80 )
  {
    if ( n32785 == 32771 )
    {
      result = unk_193C0F0;
      *(_DWORD *)(unk_193C0F0 + 80) = 0;
    }
    else
    {
      result = n32785 - 32785;
      if ( n32785 == 32785 )
      {
        v3 = *(_DWORD *)(*(_DWORD *)unk_193BF80 + 16);
        sub_848820(0);
        sub_848860(0);
        sub_848880("P:");
        sub_848820(18);
        v4 = (float)v3;
        v5 = v4 * 0.0000152587890625 * 100.0;
        sub_930BA0(v5);
        sub_848820(45);
        return sub_848880(":%dk", v3 / 1024);
      }
    }
  }
  return result;
}
