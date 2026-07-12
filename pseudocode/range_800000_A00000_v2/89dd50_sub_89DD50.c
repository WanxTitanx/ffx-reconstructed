// Function: sub_89DD50
// Address: 0x89dd50
int sub_89DD50(char *Format, ...)
{
  char Buffer[256]; // [esp+0h] [ebp-104h] BYREF
  va_list va; // [esp+110h] [ebp+Ch] BYREF

  va_start(va, Format);
  vsprintf(Buffer, Format, va);
  return sub_89DE30(Buffer);
}
