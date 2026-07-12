// Function: sub_994050
// Address: 0x994050
int __thiscall sub_994050(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int v5; // edi
  int v6; // eax
  int v7; // esi
  int v8; // ebx
  int v10; // [esp+14h] [ebp-18h]
  int v11; // [esp+18h] [ebp-14h]
  int v12; // [esp+1Ch] [ebp-10h]

  v12 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)*a2 + 44))(*a2, 36);
  if ( !v12 )
    return 0;
  v5 = *(this + 2);
  v10 = *(this + 5);
  v6 = *(this + 4);
  v7 = *(this + 3);
  v11 = v6;
  v8 = a2[1];
  sub_9A8260(a2, a3, a4);
  *(_DWORD *)(v12 + 28) = v11;
  *(_DWORD *)v12 = &btConvexConvexAlgorithm::`vftable';
  *(_DWORD *)(v12 + 8) = v7;
  *(_DWORD *)(v12 + 12) = v5;
  *(_BYTE *)(v12 + 16) = 0;
  *(_DWORD *)(v12 + 20) = v8;
  *(_BYTE *)(v12 + 24) = 0;
  *(_DWORD *)(v12 + 32) = v10;
  return v12;
}
