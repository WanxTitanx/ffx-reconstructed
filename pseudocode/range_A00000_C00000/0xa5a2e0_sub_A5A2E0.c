// Function: sub_A5A2E0
// Address: 0xa5a2e0
// Size: 0x73
// Prototype: 

int __cdecl sub_A5A2E0(int a1)
{
  int v1; // edi
  int result; // eax
  int v3; // ebx
  int v4; // esi
  int v5; // eax
  int v6; // edx
  char *SlotStruct; // [esp+10h] [ebp+8h]

  v1 = buf + 832 * a1;
  SlotStruct = FFX_Party_GetSlotStruct(*(_BYTE *)(dword_2305834[0] + 71100));
  result = 0;
  v3 = 0;
  if ( *(__int16 *)(v1 + 30) > 0 )
  {
    v4 = v1 + 68;
    do
    {
      v5 = *(_DWORD *)(v4 + 4) >> 4;
      v6 = 1 << (*(_DWORD *)(v4 + 4) & 0xF);
      v4 += 12;
      *(_BYTE *)(v4 - 12) = (unsigned __int16)(v6 & *(_WORD *)&SlotStruct[2 * v5 + 62]) == 0;
      result = *(__int16 *)(v1 + 30);
      ++v3;
    }
    while ( v3 < result );
  }
  return result;
}

