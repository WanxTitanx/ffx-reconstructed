// Function: sub_8EB590
// Address: 0x8eb590
_DWORD *__cdecl sub_8EB590(_DWORD *a1, __int16 a2, int a3, int a4, int a5)
{
  char *MagicEntryById; // eax
  int v6; // ebx
  _DWORD *result; // eax
  int v8; // [esp-Ch] [ebp-1Ch]
  int v9; // [esp+Ch] [ebp-4h] BYREF

  MagicEntryById = FFX_Battle_GetMagicEntryById(a2, &v9);
  v6 = v9 + *(unsigned __int16 *)MagicEntryById;
  v8 = (unsigned __int8)MagicEntryById[20];
  dword_187168C = a1;
  dword_187168C = (_DWORD *)sub_8EB240(a1, a3 + 3, a4 + 1, v8);
  result = (_DWORD *)sub_8ED0A0(dword_187168C, v6, a3 + 22, a4, a5);
  dword_187168C = result;
  return result;
}
