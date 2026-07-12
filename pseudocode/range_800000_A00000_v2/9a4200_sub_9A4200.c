// Function: sub_9A4200
// Address: 0x9a4200
int (__cdecl *__stdcall sub_9A4200(int a1))(_DWORD)
{
  int (__cdecl *result)(_DWORD); // eax

  if ( *(_DWORD *)(a1 + 108) )
  {
    result = unk_193F644;
    if ( unk_193F644 )
    {
      result = (int (__cdecl *)(_DWORD))unk_193F644(*(_DWORD *)(a1 + 108));
      *(_DWORD *)(a1 + 108) = 0;
    }
  }
  return result;
}
