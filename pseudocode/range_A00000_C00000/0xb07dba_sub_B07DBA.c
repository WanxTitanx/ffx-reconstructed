// Function: sub_B07DBA
// Address: 0xb07dba
// Size: 0xa
// Prototype: void __cdecl()

void __cdecl sub_B07DBA()
{
  DeleteCriticalSection(&lpCriticalSection__0);
  if ( unk_193FCF0 )
  {
    free(unk_193FCF0);
    unk_193FCF0 = 0;
  }
  unk_193FCF4 = 0;
  unk_193FCF8 = 0;
}

