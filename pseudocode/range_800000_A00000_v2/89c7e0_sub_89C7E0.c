// Function: sub_89C7E0
// Address: 0x89c7e0
int sub_89C7E0()
{
  int n20; // edi
  int v1; // esi
  int result; // eax
  float v3; // [esp+4h] [ebp-1Ch]
  int n5; // [esp+8h] [ebp-18h]
  float v5; // [esp+14h] [ebp-Ch]
  float v6; // [esp+14h] [ebp-Ch]
  int v7; // [esp+18h] [ebp-8h] BYREF
  int v8; // [esp+1Ch] [ebp-4h] BYREF

  if ( unk_133D6A0 != 1 )
  {
    n20 = 0;
    v1 = 1;
    do
    {
      if ( (v1 & unk_133D138) != 0 )
      {
        sub_795930(n20, &v7, &v8);
        nullsub_163();
        if ( n20 >= 20 )
          n5 = 5;
        else
          n5 = 4;
        v5 = (float)v8;
        v3 = v5;
        v6 = (float)v7;
        result = sub_8C0640(v6, v3, n5);
      }
      v1 = __ROL4__(v1, 1);
      ++n20;
    }
    while ( n20 < 28 );
  }
  return result;
}
