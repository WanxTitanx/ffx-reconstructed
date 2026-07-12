// Function: sub_881B60
// Address: 0x881b60
int __cdecl sub_881B60(int a1, int a2)
{
  int v2; // ebx
  int v3; // edi
  int v4; // ecx
  int v5; // esi
  int result; // eax
  int v7; // eax
  int ActorByIndex; // eax
  int v9; // [esp-8h] [ebp-7Ch]
  int v10; // [esp+Ch] [ebp-68h]
  int v11; // [esp+10h] [ebp-64h]
  int n30; // [esp+18h] [ebp-5Ch]
  int v13; // [esp+1Ch] [ebp-58h]
  int v14[12]; // [esp+20h] [ebp-54h] BYREF
  char Buffer[32]; // [esp+50h] [ebp-24h] BYREF

  v2 = a2 + 2;
  sub_86AF30(0);
  v3 = (dword_1328AC0[unk_1328AB0] + word_C53414[4 * unk_1328AB0]) << 6;
  v4 = sub_86B8A0() - 1;
  v5 = *(_DWORD *)((char *)&unk_1328AE8 + v3);
  v11 = *(_DWORD *)((char *)&unk_1328ADC + v3);
  result = a2 + 14;
  v10 = v4;
  *(_DWORD *)((char *)&unk_1328B04 + v3) = v4;
  n30 = 0;
  v13 = a2 + 14;
  do
  {
    if ( v4 < v5 )
      break;
    v7 = sub_86B6D0(v5, v14);
    v9 = a1 + 100;
    if ( v7 )
    {
      sub_88FA60(v9, v2);
      sprintf(Buffer, "0x%x", v14[1]);
      sub_88F530(unk_1328A34, 0, Buffer);
      sub_88FA60(a1 + 106, v2);
      ActorByIndex = FFX_Field_GetActorByIndex(v14[0]);
      result = sub_87AF20(ActorByIndex);
    }
    else
    {
      sub_88FA60(v9, v2);
      sub_88F530(unk_1328A34, 0, "----");
      sub_88FA60(a1 + 106, v2);
      result = sub_88F430(unk_1328A34, 0, "disp off");
    }
    if ( v5 == v11 )
      result = sub_88FAA0(2, 0, a1 + 4, v13, a1 + 360, v13);
    v13 += 13;
    ++v5;
    v2 += 13;
    ++n30;
    v4 = v10;
  }
  while ( n30 < 30 );
  return result;
}
