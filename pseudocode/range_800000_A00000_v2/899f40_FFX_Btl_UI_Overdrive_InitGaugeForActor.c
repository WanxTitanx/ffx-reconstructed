// Function: FFX_Btl_UI_Overdrive_InitGaugeForActor
// Address: 0x899f40
int __cdecl FFX_Btl_UI_Overdrive_InitGaugeForActor(int a1)
{
  unsigned __int16 v1; // ax
  __int16 v2; // si
  int i; // edx
  int v4; // eax
  __int16 v5; // si
  int j; // edx
  unsigned __int16 v7; // ax
  __int16 v8; // si
  int k; // edx
  int v10; // esi
  float v12; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v13[4]; // [esp+10h] [ebp-4h] BYREF

  memset(byte_133F580, 0, 0x58u);
  unk_133F584 = 0;
  *(_WORD *)byte_133F580 = a1;
  *(_WORD *)&byte_133F580[2] = 20;
  unk_133F5D4 = FFX_Btl_GetActorCtbGaugeCurrent(a1);
  unk_133F5D6 = FFX_Btl_GetActorCtbTurns(a1);
  v1 = sub_78F980(byte_133F580[0]);
  v2 = unk_133F586;
  for ( i = 0; i < 12; ++i )
  {
    if ( ((v1 >> i) & 1) != 0 )
    {
      unk_133F588[v2] = i + 4102;
      v2 = ++unk_133F586;
    }
  }
  v4 = sub_78FAD0(byte_133F580[0]);
  v5 = unk_133F586;
  for ( j = 0; j < 13; ++j )
  {
    if ( *(_BYTE *)(v4 + j) )
    {
      unk_133F588[v5] = j + 4114;
      v5 = ++unk_133F586;
    }
  }
  v7 = sub_78F9A0(byte_133F580[0]);
  v8 = unk_133F586;
  for ( k = 0; k < 15; ++k )
  {
    if ( ((v7 >> k) & 1) != 0 )
    {
      unk_133F588[v8] = k + 4128;
      v8 = ++unk_133F586;
    }
  }
  v10 = sub_78F810(a1, 1);
  sub_8B9600(0, v10, &v12, v13, 0, 0);
  n2_15 = 2;
  unk_133F5EC[0] = (int)v12;
  unk_133F5F0 = v10;
  unk_133F648 = 1;
  return 1;
}
