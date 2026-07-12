// Function: sub_8E3BC0
// Address: 0x8e3bc0
int __cdecl sub_8E3BC0(int a1)
{
  int v2; // edi
  int v3; // eax
  unsigned __int16 v4; // ebx^2
  int v5; // eax
  int v6; // ebx
  int v7; // ecx
  int v8; // ebx
  int v9; // ebx
  int v11; // [esp+Ch] [ebp-Ch]
  int v12; // [esp+10h] [ebp-8h]
  int v13; // [esp+14h] [ebp-4h]
  int v14; // [esp+20h] [ebp+8h]
  int v15; // [esp+20h] [ebp+8h]

  v2 = 0;
  v3 = sub_8DC9D0(*(_DWORD *)(a1 + 36), 0);
  v4 = HIWORD(v3);
  v14 = (unsigned __int16)v3;
  v5 = *(_DWORD *)(a1 + 88);
  v6 = v4;
  v11 = v6;
  if ( v5 )
  {
    v6 += 38;
    v13 = (unsigned __int16)sub_8DC9D0(v5, 0);
    v2 = (unsigned __int16)sub_8DC9D0(*(_DWORD *)(a1 + 92), 0);
    if ( v13 > v2 )
      v2 = v13;
  }
  v12 = *(_DWORD *)(a1 + 96) + (198 - v6) / 2;
  if ( sub_8DCF20((476 - v14) / 2, v12, v14 + 36, v6 + 10) )
  {
    sub_8DCC50(*(_DWORD *)(a1 + 36), 0, (476 - v14) / 2 + 18, v12 + 5);
    v7 = *(_DWORD *)(a1 + 88);
    if ( v7 )
    {
      v8 = v11 + 8 + v12 + 5;
      v15 = (476 - v2) / 2;
      sub_8DCB60(v7, v15, v8);
      if ( !*(_WORD *)(a1 + 72) )
        sub_8DCA00(v15, v8, v2);
      v9 = v8 + 15;
      sub_8DCB60(*(_DWORD *)(a1 + 92), v15, v9);
      if ( *(_WORD *)(a1 + 72) )
        sub_8DCA00(v15, v9, v2);
    }
  }
  return sub_8DD420();
}
