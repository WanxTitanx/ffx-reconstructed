// Function: sub_A3E860
// Address: 0xa3e860
// Size: 0x14b

int __cdecl sub_A3E860(int a1, int a2, _DWORD *a3, int *a4, int a5)
{
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  int v7; // ebx
  int v8; // esi
  _DWORD *v10; // eax
  _DWORD *v11; // ecx
  int v12; // esi

  v5 = (_DWORD *)sub_42FC20(56); /*0xa3e888*/
  v6 = v5; /*0xa3e88d*/
  if ( v5 ) /*0xa3e89e*/
  {
    *v5 = 0; /*0xa3e8a0*/
    v5[1] = 0; /*0xa3e8a6*/
    v5[2] = 0; /*0xa3e8ad*/
    sub_583CB0(v5 + 3); /*0xa3e8bb*/
    v6[12] = a1; /*0xa3e8c3*/
    v6[13] = 0; /*0xa3e8c6*/
  }
  else
  {
    v6 = 0; /*0xa3e8cf*/
  }
  *a4 = (int)v6; /*0xa3e8db*/
  if ( !v6 ) /*0xa3e8df*/
    return 14; /*0xa3e8df*/
  v7 = sub_A29EE0(v6, (int)a4, a2, a5); /*0xa3e8f2*/
  if ( !v7 ) /*0xa3e8f6*/
  {
    v10 = (_DWORD *)sub_42FC20(408); /*0xa3e92d*/
    if ( v10 ) /*0xa3e941*/
      v11 = sub_A29360(v10, *a4, 0); /*0xa3e94e*/
    else
      v11 = 0; /*0xa3e952*/
    *a3 = v11; /*0xa3e95e*/
    if ( v11 ) /*0xa3e962*/
      return 0; /*0xa3e997*/
    v12 = *a4; /*0xa3e964*/
    if ( *a4 ) /*0xa3e964... [1344 chars total]