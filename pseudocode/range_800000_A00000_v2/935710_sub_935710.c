// Function: sub_935710
// Address: 0x935710
void __cdecl sub_935710(int a1, int a2)
{
  int v2; // esi

  if ( unk_193C0F0 )
  {
    switch ( a2 )
    {
      case 32769:
        sub_937780(a1, dword_C5F6F0);
        if ( !sub_919EF0() )
          nullsub_167();
        break;
      case 32771:
        *(_DWORD *)(unk_193C0F0 + 40) = 0;
        break;
      case 32785:
        if ( sub_919EF0() )
        {
          v2 = sub_919F00(0);
          sub_919F10(v2, 0);
          sub_919F10(v2, 1);
        }
        break;
      default:
        return;
    }
  }
}
