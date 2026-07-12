// Function: sub_A5AA30
// Address: 0xa5aa30
// Size: 0x26a
// Prototype: 

int __cdecl sub_A5AA30(int a1, int a2)
{
  char *EntryByIdRange; // esi
  __int16 v3; // bx
  char v4; // al
  int result; // eax
  int CommandEntryById; // edi
  int v7; // esi
  char v8; // [esp-4h] [ebp-10h]
  char v9; // [esp-4h] [ebp-10h]
  char v10; // [esp-4h] [ebp-10h]
  char v11; // [esp-4h] [ebp-10h]
  int v12; // [esp+8h] [ebp-4h] BYREF

  EntryByIdRange = FFX_Table_GetEntryByIdRange(
                     *(unsigned __int16 *)(dword_2305834[0] + 40 * a2 + 2062),
                     (__int16 *)unk_1A860E0,
                     &v12);
  v3 = *((_WORD *)EntryByIdRange + 8);
  *(_WORD *)(dword_2305834[0] + 71270) = 120;
  *(_DWORD *)(dword_2305834[0] + 71260) = 0;
  *(_DWORD *)(dword_2305834[0] + 71256) = 0;
  *(_DWORD *)(dword_2305834[0] + 71264) = (unsigned __int8)EntryByIdRange[20];
  v4 = sub_7852B0();
  *(_DWORD *)(dword_2305834[0] + 71252) = FFX_Table_GetKernelString(9, 33, v4 & 1);
  *(_DWORD *)(dword_2305834[0] + 71256) = sub_8AC800(a1);
  *(_WORD *)(dword_2305834[0] + 71268) = 0;
  if ( (v3 & 1) != 0 )
  {
    v8 = sub_7852B0() & 1;
    result = FFX_Table_GetKernelString(11, 7, v8);
LABEL_9:
    *(_DWORD *)(dword_2305834[0] + 71260) = result;
    return result;
  }
  if ( (v3 & 2) != 0 )
  {
    v9 = sub_7852B0() & 1;
    result = FFX_Table_GetKernelString(11, 8, v9);
    goto LABEL_9;
  }
  if ( (v3 & 4) != 0 )
  {
    v10 = sub_7852B0() & 1;
    result = FFX_Table_GetKernelString(11, 9, v10);
    goto LABEL_9;
  }
  if ( (v3 & 8) != 0 )
  {
    v11 = sub_7852B0() & 1;
    result = FFX_Table_GetKernelString(11, 10, v11);
    goto LABEL_9;
  }
  if ( (v3 & 0x10) != 0 )
  {
    result = sub_A56FC0(11);
    *(_DWORD *)(dword_2305834[0] + 71260) = result;
  }
  else if ( (v3 & 0x20) != 0 )
  {
    result = sub_A56FC0(12);
    *(_DWORD *)(dword_2305834[0] + 71260) = result;
  }
  else if ( (v3 & 0x40) != 0 )
  {
    result = sub_A56FC0(13);
    *(_DWORD *)(dword_2305834[0] + 71260) = result;
  }
  else if ( (v3 & 0x80u) == 0 )
  {
    if ( (v3 & 0x100) != 0 )
    {
      *(_DWORD *)(dword_2305834[0] + 71260) = sub_A56FC0(0);
      result = 50 * *(_DWORD *)(dword_2305834[0] + 71264);
      *(_DWORD *)(dword_2305834[0] + 71264) = result;
    }
    else if ( (v3 & 0x200) != 0 )
    {
      *(_DWORD *)(dword_2305834[0] + 71260) = sub_A56FC0(1);
      result = 5 * *(_DWORD *)(dword_2305834[0] + 71264);
      *(_DWORD *)(dword_2305834[0] + 71264) = result;
    }
    else
    {
      result = *((unsigned __int16 *)EntryByIdRange + 9);
      if ( (_WORD)result )
      {
        CommandEntryById = FFX_Kernel_GetCommandEntryById(result, (int)&a2);
        *(_DWORD *)(dword_2305834[0] + 71252) = sub_A567D0(32);
        v7 = a2;
        *(_DWORD *)(dword_2305834[0] + 71260) = v7 + *(unsigned __int16 *)(CommandEntryById + 4 * (sub_7852B0() & 1));
        result = dword_2305834[0];
        *(_WORD *)(dword_2305834[0] + 71268) = 1;
      }
    }
  }
  else
  {
    result = sub_A56FC0(14);
    *(_DWORD *)(dword_2305834[0] + 71260) = result;
  }
  return result;
}

