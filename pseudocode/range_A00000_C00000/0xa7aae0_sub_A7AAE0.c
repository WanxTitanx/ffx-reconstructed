// Function: sub_A7AAE0
// Address: 0xa7aae0
// Size: 0x2e5
// Prototype: 

int __cdecl sub_A7AAE0(int a1, int *a2, int n2, int a4)
{
  int n2290; // ebx
  int n7933954; // edi
  int v6; // eax
  int ActorByIndex; // eax
  int ChrPointer; // eax
  char *ChrPointer_1; // esi
  int n205; // eax
  int n121; // ecx
  int n2255; // ecx
  int n7; // ecx
  bool v14; // zf
  int n5; // ecx
  int v17; // [esp+Ch] [ebp-Ch]
  int v18; // [esp+10h] [ebp-8h]
  int n1900; // [esp+14h] [ebp-4h]

  n2290 = FFX_FieldVM_PopOperand(a1, a2);
  n1900 = FFX_FieldVM_PopOperand(a1, a2);
  v18 = FFX_FieldVM_PopOperand(a1, a2);
  v17 = FFX_FieldVM_PopOperand(a1, a2);
  n7933954 = FFX_FieldVM_PopOperand(a1, a2);
  if ( a4 )
  {
    v6 = FFX_FieldVM_PopOperand(a1, a2);
    ActorByIndex = FFX_Field_GetActorByIndex(v6);
    ChrPointer = FFX_TK_GetChrPointer(ActorByIndex);
  }
  else
  {
    ChrPointer = FFX_TK_GetChrPointer(a1);
  }
  ChrPointer_1 = (char *)ChrPointer;
  if ( !ChrPointer )
    return 0;
  n205 = n205;
  if ( n205 == 205 )
  {
    if ( FFX_Btl_GetGlobalModeId() == 2085 )
    {
      n121 = *(unsigned __int16 *)ChrPointer_1;
      if ( n121 == 121 && n7933954 == 7933954 )
      {
        if ( n1900 == 1900 && n2290 == 2290 )
          ChrPointer_1[2160] = 0;
        if ( n1900 == 2290 && n2290 == -1 )
          ChrPointer_1[2160] = 1;
      }
      if ( (_WORD)n121 == 16395 && n7933954 == 1074466823 )
      {
        if ( n1900 == 1900 && n2290 == 2253 )
          ChrPointer_1[2160] = 0;
        if ( n1900 == 2255 )
        {
          n2255 = 2255;
          if ( n2290 == 2263 )
            ChrPointer_1[2160] = 1;
          goto LABEL_62;
        }
      }
LABEL_61:
      n2255 = n1900;
      goto LABEL_62;
    }
    n205 = n205;
  }
  if ( n205 == 364 )
  {
    if ( FFX_Btl_GetGlobalModeId() == 1176 )
    {
      n7 = *(unsigned __int16 *)ChrPointer_1;
      if ( n7 == 7 )
      {
        if ( n7933954 == 462952 && n1900 == 44 && n2290 == 66 )
          ChrPointer_1[2160] = 0;
        if ( n7933954 == 462953 && n1900 == 68 && n2290 == 98 )
          ChrPointer_1[2160] = 1;
      }
      v14 = (_WORD)n7 == 20586;
      n2255 = n1900;
      if ( v14 && n7933954 == 1349128192 && n1900 == 44 && n2290 == -1 )
        ChrPointer_1[2160] = 0;
      goto LABEL_62;
    }
    n205 = n205;
  }
  if ( n205 != 17 || FFX_Btl_GetGlobalModeId() != 200 )
    goto LABEL_61;
  n5 = *(unsigned __int16 *)ChrPointer_1;
  if ( n5 == 5 )
  {
    if ( n7933954 == 331894 && !n1900 && n2290 == -1 )
      ChrPointer_1[2160] = 0;
    if ( n7933954 == 331895 && !n1900 && n2290 == -1 )
      ChrPointer_1[2160] = 1;
  }
  v14 = (_WORD)n5 == 16385;
  n2255 = n1900;
  if ( v14 )
  {
    if ( n7933954 == 1073811457 && !n1900 && n2290 == -1 )
      ChrPointer_1[2160] = 0;
    if ( n7933954 == 1073811458 && !n1900 && n2290 == -1 )
      ChrPointer_1[2160] = 1;
  }
LABEL_62:
  if ( *(_WORD *)ChrPointer_1 == 102 )
    unk_1300898 = n7933954 == 135314;
  if ( n2 )
  {
    if ( n2 == 1 )
    {
      sub_837460(ChrPointer_1, n7933954, v17, v18, n2255, n2290);
      return 0;
    }
    if ( n2 == 2 )
    {
      sub_837540(ChrPointer_1, n7933954, v17, v18, n2255, n2290);
      return 0;
    }
  }
  else
  {
    sub_8373D0(ChrPointer_1, n7933954, v17, v18, n2255, n2290);
  }
  return 0;
}

