// Function: sub_9BB440
// Address: 0x9bb440
char __thiscall sub_9BB440(int this, int a2)
{
  int v3; // edx
  int *v4; // ecx
  int v5; // edx
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  int v10; // [esp-8h] [ebp-34h]
  _BYTE v11[4]; // [esp+Ch] [ebp-20h] BYREF
  int v12; // [esp+10h] [ebp-1Ch]
  int v13; // [esp+14h] [ebp-18h]
  int v14; // [esp+18h] [ebp-14h]
  char v15; // [esp+1Ch] [ebp-10h]
  int v16; // [esp+28h] [ebp-4h]

  v3 = *(_DWORD *)(this + 96);
  if ( *(_DWORD *)a2 == v3
    || (*(_WORD *)(a2 + 4) & *(_WORD *)(this + 10)) == 0
    || (*(_WORD *)(a2 + 6) & *(_WORD *)(this + 8)) == 0 )
  {
    return 0;
  }
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD, int, _DWORD))(**(_DWORD **)(this + 108) + 24))(
         *(_DWORD *)(this + 108),
         v3,
         *(_DWORD *)a2) )
  {
    v15 = 1;
    v14 = 0;
    v12 = 0;
    v13 = 0;
    v4 = *(int **)(this + 104);
    v5 = *v4;
    v10 = *(_DWORD *)(*(_DWORD *)(this + 96) + 200);
    v16 = 0;
    v6 = (*(int (__thiscall **)(int *, int, int))(v5 + 48))(v4, v10, a2);
    if ( v6 )
    {
      if ( *(_DWORD *)(v6 + 8) )
      {
        v12 = 0;
        (*(void (__thiscall **)(_DWORD, _BYTE *))(**(_DWORD **)(v6 + 8) + 12))(*(_DWORD *)(v6 + 8), v11);
        v7 = 0;
        if ( v12 > 0 )
        {
          v8 = v14;
          while ( *(int *)(*(_DWORD *)(v14 + 4 * v7) + 1176) <= 0 )
          {
            if ( ++v7 >= v12 )
              goto LABEL_15;
          }
          v16 = -1;
          sub_97A860(v11);
          return 0;
        }
      }
    }
    v8 = v14;
LABEL_15:
    v16 = -1;
    if ( v8 )
    {
      if ( v15 )
        sub_9D4D50(v8);
    }
  }
  return 1;
}
