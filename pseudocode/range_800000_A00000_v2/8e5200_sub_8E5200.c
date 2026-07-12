// Function: sub_8E5200
// Address: 0x8e5200
char *__cdecl sub_8E5200(char *_FFX_Data_GameData_PS3Data_magic)
{
  char *_FFX_Data_GameData_PS3Data_magic_1; // eax
  int n10; // esi
  const char *v3; // edi
  int n10_1; // ebx

  _FFX_Data_GameData_PS3Data_magic_1 = _FFX_Data_GameData_PS3Data_magic;
  n10 = 0;
  if ( n10_2 <= 0 )
  {
LABEL_7:
    if ( n10_2 < 10 )
    {
      n10_1 = n10_2 + 1;
      qmemcpy((char *)&unk_18756D0 + 256 * n10_2, _FFX_Data_GameData_PS3Data_magic_1, 0x100u);
      n10_2 = n10_1;
    }
  }
  else
  {
    v3 = (const char *)&unk_18756D0;
    while ( 1 )
    {
      _FFX_Data_GameData_PS3Data_magic_1 = (char *)strcmp(v3, _FFX_Data_GameData_PS3Data_magic_1);
      if ( _FFX_Data_GameData_PS3Data_magic_1 )
        _FFX_Data_GameData_PS3Data_magic_1 = (char *)((int)_FFX_Data_GameData_PS3Data_magic_1 < 0 ? -1 : 1);
      if ( !_FFX_Data_GameData_PS3Data_magic_1 )
        break;
      _FFX_Data_GameData_PS3Data_magic_1 = _FFX_Data_GameData_PS3Data_magic;
      ++n10;
      v3 += 256;
      if ( n10 >= n10_2 )
        goto LABEL_7;
    }
  }
  return _FFX_Data_GameData_PS3Data_magic_1;
}
