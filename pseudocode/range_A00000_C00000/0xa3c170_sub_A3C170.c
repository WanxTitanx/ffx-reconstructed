// Function: sub_A3C170
// Address: 0xa3c170
// Size: 0x3e
// Prototype: _DWORD __cdecl(int, const char *CreateTexture2D, const char *_creating_rendertarget)

int __cdecl sub_A3C170(int a1, const char *CreateTexture2D, const char *_creating_rendertarget)
{
  if ( a1 == -2147024882 )
    return IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", CreateTexture2D, _creating_rendertarget);
  else
    return IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", CreateTexture2D, _creating_rendertarget, a1);
}

