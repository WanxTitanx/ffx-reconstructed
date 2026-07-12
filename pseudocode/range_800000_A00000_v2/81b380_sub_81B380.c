// Function: sub_81B380
// Address: 0x81b380
int __cdecl sub_81B380(int a1, float a2)
{
  int result; // eax

  if ( sub_780D80() )
    return FFX_BtlActor_SetActorScale(a1, a2);
  result = LODWORD(flt_12A80C0[a1]);
  if ( result )
    return sub_82B230(result, a2);
  return result;
}
