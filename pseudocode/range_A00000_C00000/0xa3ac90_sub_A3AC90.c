// Function: sub_A3AC90
// Address: 0xa3ac90
// Size: 0x320

int __stdcall sub_A3AC90(_DWORD *a1, int a2, char *a3, int a4, int a5)
{
  _DWORD *v5; // edx
  char *v6; // edi
  char **v7; // esi
  _DWORD *v9; // esi
  int v10; // ecx
  int v11; // edx
  int v13; // ebx
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  _DWORD *v17; // ecx
  int v18; // edx
  int v19; // edx
  _DWORD v20[4]; // [esp+8h] [ebp-18h] BYREF
  int v21; // [esp+18h] [ebp-8h]
  int v22; // [esp+1Ch] [ebp-4h]
  int v23; // [esp+28h] [ebp+8h]
  int v24; // [esp+30h] [ebp+10h]
  int v25; // [esp+34h] [ebp+14h]

  v5 = dword_1A858B4; /*0xa3ac93*/
  v6 = 0; /*0xa3aca6*/
  v7 = (char **)(dword_1A858B4[683] + 28); /*0xa3aca8*/
  if ( !dword_1A858B4[438] || !dword_1A858B4[439] )
  {
    IggyGDrawSendWarning(0, "GDraw warning: w=0,h=0 rendertarget");
    return 0; /*0xa3afa6*/
  }
  if ( v7 >= dword_1A858B4 + 683 ) /*0xa3acc5*/
  {
    IggyGDrawSendWarning(0, "GDraw rendertarget nesting exceeds MAX_RENDER_STACK_DEPTH"); /*0xa3accd*/
    return 0; /*0xa3acdd*/
  }
  if ( !a4 )... [4119 chars total]