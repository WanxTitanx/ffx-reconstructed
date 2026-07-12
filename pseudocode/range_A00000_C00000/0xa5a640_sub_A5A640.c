// Function: sub_A5A640
// Address: 0xa5a640
// Size: 0xd3
// Prototype: 

int __cdecl sub_A5A640(int a1, int a2)
{
  char *EntryByIdRange; // edi
  char *v3; // ebx
  char v4; // al
  int v5; // esi
  int v6; // esi
  int result; // eax
  int v8; // [esp+Ch] [ebp-4h] BYREF

  EntryByIdRange = FFX_Table_GetEntryByIdRange(
                     *(unsigned __int16 *)(dword_2305834[0] + 40 * a2 + 2062),
                     (__int16 *)unk_1A860E0,
                     &a2);
  v3 = FFX_Table_GetEntryByIdRange(a1, (__int16 *)unk_1A860E0, &v8);
  *(_WORD *)(dword_2305834[0] + 71270) = 120;
  *(_DWORD *)(dword_2305834[0] + 71264) = 0;
  v4 = sub_7852B0();
  *(_DWORD *)(dword_2305834[0] + 71252) = FFX_Table_GetKernelString(9, 34, v4 & 1);
  v5 = a2;
  *(_DWORD *)(dword_2305834[0] + 71256) = v5 + *(unsigned __int16 *)&EntryByIdRange[4 * (sub_7852B0() & 1)];
  v6 = v8;
  *(_DWORD *)(dword_2305834[0] + 71260) = v6 + *(unsigned __int16 *)&v3[4 * (sub_7852B0() & 1)];
  result = dword_2305834[0];
  *(_WORD *)(dword_2305834[0] + 71268) = 2;
  return result;
}

