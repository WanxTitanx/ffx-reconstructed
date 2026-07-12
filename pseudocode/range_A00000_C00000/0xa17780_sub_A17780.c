// Function: sub_A17780
// Address: 0xa17780
// Size: 0xd2
// Prototype: 

int __userpurge sub_A17780@<eax>(_DWORD *a1@<ecx>, int a2@<edi>, int a3, int a4, int a5)
{
  char v6; // dl
  void **v7; // ecx
  char v10; // bl
  void **v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edx
  int v15; // edi
  int v16; // edx
  int v17; // eax
  int v19; // [esp+14h] [ebp+10h]

  if ( a1[24] || a1[25] )
    return 22;
  v6 = *(_BYTE *)(a4 + 4);
  if ( v6 )
    v7 = 0;
  else
    v7 = *(void ***)a4;
  if ( *v7 != &unk_CA3314 )
    return 5;
  v10 = *(_BYTE *)(a5 + 4);
  if ( v10 )
    v11 = 0;
  else
    v11 = *(void ***)a5;
  if ( *v11 != &unk_CA3364 )
    return 5;
  v12 = v6 ? 0 : *(_DWORD *)a4;
  v19 = *(_DWORD *)(v12 + 28);
  v13 = v10 ? 0 : *(_DWORD *)a5;
  if ( v19 != *(_DWORD *)(v13 + 28) )
    return 5;
  v14 = v6 ? 0 : *(_DWORD *)a4;
  v15 = *(_DWORD *)(v14 + 32);
  v16 = v10 ? 0 : *(_DWORD *)a5;
  if ( v15 != *(_DWORD *)(v16 + 32) )
    return 5;
  a1[24] = a4;
  a1[25] = a5;
  v17 = sub_A05E70(a3, a2);
  a1[26] = v17;
  return v17 != 0 ? 0 : 14;
}

