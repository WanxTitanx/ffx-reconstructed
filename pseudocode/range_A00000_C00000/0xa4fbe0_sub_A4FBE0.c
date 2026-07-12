// Function: sub_A4FBE0
// Address: 0xa4fbe0
// Size: 0x254

int sub_A4FBE0()
{
  unsigned __int8 v0; // cl
  int v1; // eax
  int result; // eax
  unsigned __int8 n4; // cl
  int n160; // ebx
  int v5; // esi
  int v6; // edx
  int v7; // esi
  int v8; // edx
  int n19; // [esp+20h] [ebp-10h] BYREF
  float v10; // [esp+24h] [ebp-Ch]
  float v11[2]; // [esp+28h] [ebp-8h] BYREF

  if ( *(_BYTE *)(dword_2305834[0] + 71106) ) /*0xa4fbef*/
  {
    if ( *(_BYTE *)(dword_2305834[0] + 71104) ) /*0xa4fbf8*/
    {
      v1 = 5 * (3 - *(unsigned __int8 *)(dword_2305834[0] + 71105)); /*0xa4fc1d*/
      v0 = *(_BYTE *)(dword_2305834[0] + 71105); /*0xa4fc20*/
    }
    else
    {
      v0 = *(_BYTE *)(dword_2305834[0] + 71105); /*0xa4fc01*/
      v1 = 5 * v0; /*0xa4fc0a*/
    }
    result = 32 * v1; /*0xa4fc29*/
    n4 = v0 + 1; /*0xa4fc2d*/
    n160 = result / 4 + 32; /*0xa4fc35*/
    *(_BYTE *)(dword_2305834[0] + 71105) = n4; /*0xa4fc38*/
    if ( n4 >= 4u ) /*0xa4fc41*/
    {
      *(_BYTE *)(dword_2305834[0] + 71106) = 0; /*0xa4fc48*/
      result = dwor... [2585 chars total]