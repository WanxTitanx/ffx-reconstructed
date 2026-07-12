// Function: sub_9BDD30
// Address: 0x9bdd30
void *__usercall sub_9BDD30@<eax>(int a1@<ebp>)
{
  double v1; // st7
  float v3; // [esp+8h] [ebp-38h]
  float v4; // [esp+14h] [ebp-2Ch] BYREF
  int v5; // [esp+18h] [ebp-28h]
  int v6; // [esp+1Ch] [ebp-24h]
  int v7; // [esp+20h] [ebp-20h]
  int *v8; // [esp+24h] [ebp-1Ch]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+28h] [ebp-18h]
  void *v10; // [esp+2Ch] [ebp-14h]
  int v11; // [esp+30h] [ebp-10h]
  int v12; // [esp+34h] [ebp-Ch]
  void *v13; // [esp+38h] [ebp-8h]
  int v14; // [esp+3Ch] [ebp-4h] BYREF
  void *retaddr; // [esp+40h] [ebp+0h]

  v12 = a1;
  v13 = retaddr;
  v11 = -1;
  v10 = &loc_AD9EAE;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v8 = &v14;
  v1 = 0.0;
  if ( (dword_193F940[0] & 1) == 0 )
  {
    dword_193F940[0] |= 1u;
    v11 = 0;
    v4 = 0.0;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    sub_9B4570(0.0, 0, 0, &v4);
    atexit(sub_B07DA0);
    v1 = 0.0;
    v11 = -1;
  }
  v3 = v1;
  v4 = 0.0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  sub_9B5D30((int)&unk_193F680, v3, &v4);
  return &unk_193F680;
}
