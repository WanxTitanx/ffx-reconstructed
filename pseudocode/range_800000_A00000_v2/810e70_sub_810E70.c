// Function: sub_810E70
// Address: 0x810e70
int __cdecl sub_810E70(int a1, int a2, int a3)
{
  __int16 v3; // si

  v3 = *(_WORD *)(a3 + 2);
  if ( (__int16)sub_7E32F0(256) >= v3 )
    return a3 + 6;
  else
    return a3 + *(unsigned __int16 *)(a3 + 4);
}
