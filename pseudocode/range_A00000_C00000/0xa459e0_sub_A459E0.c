// Function: sub_A459E0
// Address: 0xa459e0
// Size: 0xcf
// Prototype: 

unsigned __int8 *__cdecl sub_A459E0(int a1, int a2)
{
  unsigned __int8 *i_1; // eax
  int i_4; // esi
  unsigned __int8 *i_2; // edi
  int v5; // ebx
  __int16 n64; // dx
  int v7; // ecx
  int n64_1; // eax
  __int16 v9; // dx
  int v10; // edi
  char v11[4]; // [esp+4h] [ebp-10h] BYREF
  unsigned __int8 *i; // [esp+8h] [ebp-Ch]
  unsigned __int8 *i_3; // [esp+Ch] [ebp-8h]
  int v14; // [esp+10h] [ebp-4h]

  i_1 = (unsigned __int8 *)sub_790270();
  i_4 = 0;
  for ( i = i_1; i_4 < (int)i; ++i_4 )
  {
    i_1 = (unsigned __int8 *)sub_790250(i_4, 0);
    i_2 = i_1;
    if ( *i_1 == a2 )
    {
      FFX_Kernel_GetCommandEntryById(*((_WORD *)i_1 + 1), (int)v11);
      v5 = unk_1A86108 + 832 * a1;
      v14 = *((unsigned __int16 *)i_2 + 1);
      n64 = *(_WORD *)(v5 + 30);
      i_3 = (unsigned __int8 *)(v14 - 12288);
      if ( n64 < 64 )
      {
        v7 = *(unsigned __int8 *)(v5 + 34);
        n64_1 = n64;
        v9 = n64 + 1;
        *(_WORD *)(v5 + 30) = v9;
        v10 = v5 + 12 * n64_1;
        *(_BYTE *)(v5 + 40) = v9 > *(__int16 *)(v5 + 22) * v7;
        *(_DWORD *)(v10 + 64) = v14;
        i_1 = i_3;
        *(_DWORD *)(v10 + 72) = i_3;
        *(_BYTE *)(v10 + 68) = 0;
      }
      else
      {
        nullsub_34();
        i_1 = (unsigned __int8 *)nullsub_35(0, "addMenuPrim error!!!  menu->mprimn >= MAXMENUPRIM\n", 64);
      }
    }
  }
  return i_1;
}

