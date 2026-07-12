// Function: sub_A4FA30
// Address: 0xa4fa30
// Size: 0x10b

int __cdecl sub_A4FA30(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  char *SlotStruct; // edi
  int v6; // ecx
  float v8; // [esp+2Ch] [ebp+Ch]
  float v9; // [esp+34h] [ebp+14h]

  SlotStruct = FFX_Party_GetSlotStruct(*(_BYTE *)(dword_2305834[0] + 71100)); /*0xa4fa58*/
  sub_A594C0(*a2, a4 - 15, a5); /*0xa4fa5a*/
  switch ( a2[2] ) /*0xa4fa6a*/
  {
    case 0: /*0xa4fa6a*/
      v6 = *((_DWORD *)SlotStruct + 9); /*0xa4fa71*/
      break; /*0xa4fa74*/
    case 1: /*0xa4fa6a*/
      v6 = *((_DWORD *)SlotStruct + 10); /*0xa4fa76*/
      break; /*0xa4fa79*/
    case 2: /*0xa4fa6a*/
      v6 = (unsigned __int8)SlotStruct[47]; /*0xa4fa7b*/
      break; /*0xa4fa7f*/
    case 3: /*0xa4fa6a*/
      v6 = (unsigned __int8)SlotStruct[51]; /*0xa4fa81*/
      break; /*0xa4fa85*/
    case 4: /*0xa4fa6a*/
      v6 = (unsigned __int8)SlotStruct[48]; /*0xa4fa87*/
      break; /*0xa4fa8b*/
    case 5: /*0xa4fa6a*/
      v6 = (unsigned __int8)SlotStruct[52]; /*0xa4fa8d*/
      break; /*0xa4fa91*/
    ... [1724 chars total]