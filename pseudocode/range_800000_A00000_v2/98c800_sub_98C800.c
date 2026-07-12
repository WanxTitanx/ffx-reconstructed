// Function: sub_98C800
// Address: 0x98c800
int __userpurge sub_98C800@<eax>(int a1@<ecx>, int a2@<ebp>, int a3, int a4)
{
  int v5; // edx
  int result; // eax
  int v7; // eax
  int v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // edi
  int v12; // edi
  int v13; // [esp-44h] [ebp-50h]
  int v14; // [esp-30h] [ebp-3Ch] BYREF
  int v15; // [esp-20h] [ebp-2Ch] BYREF
  int v16; // [esp-10h] [ebp-1Ch]
  int v17; // [esp-Ch] [ebp-18h]
  int v18; // [esp-8h] [ebp-14h]
  int v19; // [esp-4h] [ebp-10h]
  int v20; // [esp+0h] [ebp-Ch]
  void *v21; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v20 = a2;
  v21 = retaddr;
  v5 = *(_DWORD *)(a1 + 68);
  v17 = v5;
  if ( a4 - a3 == 1 )
  {
    result = sub_98C0F0(a1, v5, a3);
    ++*(_DWORD *)(a1 + 68);
  }
  else
  {
    v7 = sub_98C950(a3, a4);
    v18 = sub_990460(a3, a4, v7);
    v19 = *(_DWORD *)(a1 + 68);
    sub_990220(v19, a1 + 32);
    sub_990100(*(_DWORD *)(a1 + 68), a1 + 16);
    v8 = a3;
    v9 = a3;
    if ( a3 < a4 )
    {
      do
      {
        v13 = sub_98E120(&v15, v9);
        v10 = sub_98E1E0(&v14, v9);
        sub_98E410(*(_DWORD *)(a1 + 68), v10, v13);
        ++v9;
      }
      while ( v9 < a4 );
      v8 = a3;
    }
    ++*(_DWORD *)(a1 + 68);
    v11 = v18;
    v16 = *(_DWORD *)(a1 + 68);
    sub_98C800(v8, v18);
    v18 = *(_DWORD *)(a1 + 68);
    sub_98C800(v11, a4);
    v12 = *(_DWORD *)(a1 + 68) - v17;
    if ( !*(_BYTE *)(a1 + 72) )
      goto LABEL_11;
    if ( 16 * v12 > 2048 )
      sub_990810(v16, v18);
    if ( *(_BYTE *)(a1 + 72) )
    {
      result = *(_DWORD *)(a1 + 148);
      *(_DWORD *)(result + 16 * v19 + 12) = -v12;
    }
    else
    {
LABEL_11:
      result = *(_DWORD *)(a1 + 108);
      *(_DWORD *)((v19 << 6) + result + 32) = v12;
    }
  }
  return result;
}
