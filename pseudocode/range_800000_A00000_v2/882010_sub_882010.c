// Function: sub_882010
// Address: 0x882010
int __cdecl sub_882010(int a1, int a2, int n16)
{
  int v3; // esi
  int v4; // ebx
  int v5; // eax
  __int16 v6; // bx
  char Buffer[32]; // [esp+Ch] [ebp-24h] BYREF

  if ( n16 >= 16 )
  {
    v4 = sub_86AF30(0);
    v3 = sub_877370(15);
    if ( v4 )
    {
      v5 = sub_86AC50(*(_DWORD *)(v4 + 72));
      if ( v5 )
        v3 = v5 + 4 * (15 * n16 - 233);
    }
  }
  else
  {
    v3 = sub_877370(n16);
  }
  sub_88FA60(a1 + 24, a2);
  sprintf(Buffer, "%d", n16);
  sub_88F530(unk_1328A34, 0, Buffer);
  if ( !*(_DWORD *)v3 || !*(_DWORD *)(v3 + 4) )
    return sub_88F430(unk_1328A34, 0, "   Off");
  sub_88F430(unk_1328A34, 0, "   Pan:");
  sprintf(Buffer, "%d", *(unsigned __int8 *)(v3 + 32));
  sub_88F430(unk_1328A34, 0, Buffer);
  sub_88FA60(a1 + 82, a2);
  sub_88F430(unk_1328A34, 0, "Vol:");
  sprintf(Buffer, "%d", *(unsigned __int8 *)(v3 + 33));
  sub_88F430(unk_1328A34, 0, Buffer);
  sub_88FA60(a1 + 130, a2);
  if ( *(int *)v3 >= 0 )
    sub_88F430(unk_1328A34, 0, "Se");
  else
    sub_88F430(unk_1328A34, 0, "Sb:");
  sprintf(Buffer, "%06d ", *(_DWORD *)v3 & 0x7FFFFFFF);
  sub_88F430(unk_1328A34, 0, Buffer);
  v6 = **(_WORD **)(v3 + 4);
  sub_88FA60(a1 + 220, a2);
  if ( (v6 & 1) != 0 )
    sub_88F430(unk_1328A34, 0, "Ln/");
  else
    sub_88F430(unk_1328A34, 0, "Pt/");
  if ( (v6 & 2) != 0 )
    sub_88F430(unk_1328A34, 0, "Act/");
  else
    sub_88F430(unk_1328A34, 0, "Ps/");
  if ( (v6 & 4) != 0 )
    return sub_88F430(unk_1328A34, 0, "Ch");
  else
    return sub_88F430(unk_1328A34, 0, "Cam");
}
