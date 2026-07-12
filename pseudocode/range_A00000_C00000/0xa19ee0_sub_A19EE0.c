// Function: sub_A19EE0
// Address: 0xa19ee0
// Size: 0x131
// Prototype: 

int __thiscall sub_A19EE0(_DWORD *this, int a2, int *a3)
{
  int result; // eax
  int *v5; // eax
  int n2; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // eax
  int v16; // [esp+4h] [ebp-4h]

  if ( *(this + 4021) )
    return 22;
  v5 = (int *)a3[2];
  if ( !v5 )
    return 5;
  n2 = *((unsigned __int8 *)v5 + 5);
  if ( *((_BYTE *)v5 + 4) )
    v7 = 0;
  else
    v7 = *v5;
  v16 = *(_DWORD *)(v7 + 28);
  if ( *((_BYTE *)v5 + 4) )
    v8 = 0;
  else
    v8 = *v5;
  v9 = *(_DWORD *)(v8 + 32);
  if ( n2 && n2 != 2 )
    return 5;
  v10 = *a3;
  if ( !*a3 )
    return 5;
  v11 = *(_BYTE *)(v10 + 4) ? 0 : *(_DWORD *)v10;
  if ( *(_DWORD *)(v11 + 28) != v16 )
    return 5;
  v12 = *(_BYTE *)(v10 + 4) ? 0 : *(_DWORD *)v10;
  if ( *(_DWORD *)(v12 + 32) != v9 )
    return 5;
  v13 = a3[1];
  if ( !v13 || *(unsigned __int8 *)(v13 + 5) != n2 )
    return 5;
  v14 = *(_BYTE *)(v13 + 4) ? 0 : *(_DWORD *)v13;
  if ( *(_DWORD *)(v14 + 28) != v16 )
    return 5;
  v15 = *(_BYTE *)(v13 + 4) ? 0 : *(_DWORD *)v13;
  if ( *(_DWORD *)(v15 + 32) != v9 )
    return 5;
  *(this + 4069) = *a3;
  *(this + 4070) = a3[1];
  *(this + 4071) = a3[2];
  *(this + 4021) = 1;
  result = sub_A19CB0(this, a2);
  if ( !result )
  {
    result = sub_A10590(v16, v9);
    if ( !result )
      return sub_A19CF0(this);
  }
  return result;
}

