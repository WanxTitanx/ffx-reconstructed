// Function: sub_981B80
// Address: 0x981b80
// bad sp value at call has been detected, the output may be wrong!
int __usercall sub_981B80@<eax>(int *a1@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  int v5; // eax
  int i_4; // eax
  int i_1; // edx
  int v8; // eax
  int *v9; // eax
  int v10; // esi
  int result; // eax
  int v12; // eax
  int i_3; // esi
  int v14; // esi
  int v15; // eax
  int v16; // edx
  int v17; // ecx
  int v18; // ecx
  _BYTE v20[16]; // [esp+20h] [ebp-DCh] BYREF
  _BYTE v21[16]; // [esp+30h] [ebp-CCh] BYREF
  _DWORD v22[11]; // [esp+40h] [ebp-BCh] BYREF
  int i_2; // [esp+6Ch] [ebp-90h]
  int v24; // [esp+70h] [ebp-8Ch]
  int n1065353216_6; // [esp+74h] [ebp-88h]
  int n1065353216_7; // [esp+78h] [ebp-84h]
  int v27; // [esp+7Ch] [ebp-80h]
  int n1065353216; // [esp+80h] [ebp-7Ch]
  int n1065353216_1; // [esp+84h] [ebp-78h]
  int n1065353216_3; // [esp+88h] [ebp-74h]
  int v31; // [esp+8Ch] [ebp-70h]
  int n1065353216_8; // [esp+90h] [ebp-6Ch]
  int n1065353216_9; // [esp+94h] [ebp-68h]
  int v34; // [esp+98h] [ebp-64h]
  int v35; // [esp+9Ch] [ebp-60h]
  int v36; // [esp+A0h] [ebp-5Ch]
  int n1065353216_5; // [esp+A4h] [ebp-58h]
  int v38; // [esp+A8h] [ebp-54h]
  int v39; // [esp+ACh] [ebp-50h]
  int v40; // [esp+BCh] [ebp-40h]
  int n1065353216_10; // [esp+C0h] [ebp-3Ch] BYREF
  int v42; // [esp+C4h] [ebp-38h]
  int v43; // [esp+C8h] [ebp-34h]
  int v44; // [esp+CCh] [ebp-30h]
  int v45; // [esp+D8h] [ebp-24h]
  int i; // [esp+DCh] [ebp-20h]
  float v47; // [esp+E0h] [ebp-1Ch] BYREF
  int n1065353216_2; // [esp+E4h] [ebp-18h]
  int n1065353216_4; // [esp+E8h] [ebp-14h]
  int v50; // [esp+ECh] [ebp-10h]
  int v51; // [esp+F0h] [ebp-Ch]
  void *v52; // [esp+F4h] [ebp-8h]
  void *retaddr; // [esp+FCh] [ebp+0h]

  v51 = a2;
  v52 = retaddr;
  if ( (*(int (__thiscall **)(int *, int, int))(*a1 + 12))(a1, a3, a4) )
  {
    v5 = (*(int (__thiscall **)(int *))(*a1 + 12))(a1);
    if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v5 + 44))(v5) & 8) != 0 )
    {
      i_4 = (*(int (__thiscall **)(int))(*(_DWORD *)a1[6] + 32))(a1[6]);
      i_1 = 0;
      i_2 = i_4;
      n1065353216_10 = 0;
      v42 = 0;
      v43 = 0;
      v44 = 0;
      for ( i = 0; i_1 < i_2; i = i_1 )
      {
        v8 = (*(int (__thiscall **)(int, int))(*(_DWORD *)a1[6] + 36))(a1[6], i_1);
        v40 = *(_DWORD *)(v8 + 1176);
        if ( v40 > 0 )
        {
          v45 = v8 + 96;
          do
          {
            v9 = (int *)(*(int (__thiscall **)(int *))(*a1 + 12))(a1);
            v10 = *v9;
            n1065353216_4 = (int)&n1065353216_10;
            (*(void (__thiscall **)(int *, int, int, _DWORD, _DWORD, int *))(v10 + 28))(
              v9,
              v45 - 48,
              v45 - 16,
              *(float *)v45,
              *(_DWORD *)(v45 + 64),
              &n1065353216_10);
            v45 += 288;
            --v40;
          }
          while ( v40 );
        }
        i_1 = i + 1;
      }
    }
  }
  result = (*(int (__thiscall **)(int *))(*a1 + 12))(a1);
  if ( result )
  {
    v12 = (*(int (__thiscall **)(int *))(*a1 + 12))(a1);
    result = (*(int (__thiscall **)(int))(*(_DWORD *)v12 + 44))(v12);
    if ( (result & 3) != 0 )
    {
      i_3 = 0;
      for ( i = 0; i_3 < a1[2]; i = i_3 )
      {
        result = a1[4];
        v14 = *(_DWORD *)(result + 4 * i_3);
        if ( (*(_BYTE *)(v14 + 216) & 0x20) == 0 )
        {
          result = (*(int (__thiscall **)(int *))(*a1 + 12))(a1);
          if ( result )
          {
            v15 = (*(int (__thiscall **)(int *))(*a1 + 12))(a1);
            result = (*(int (__thiscall **)(int))(*(_DWORD *)v15 + 44))(v15);
            if ( (result & 1) != 0 )
            {
              switch ( *(_DWORD *)(v14 + 228) )
              {
                case 1:
                  n1065353216 = 1065353216;
                  v47 = 1.0;
                  n1065353216_1 = 1065353216;
                  n1065353216_2 = 1065353216;
                  n1065353216_3 = 1065353216;
                  v31 = 0;
                  n1065353216_4 = 1065353216;
                  break;
                case 2:
                  v36 = 0;
                  v47 = 0.0;
                  n1065353216_5 = 1065353216;
                  n1065353216_2 = 1065353216;
                  v38 = 0;
                  v39 = 0;
                  n1065353216_4 = 0;
                  break;
                case 3:
                  v24 = 0;
                  v47 = 0.0;
                  n1065353216_6 = 1065353216;
                  n1065353216_2 = 1065353216;
                  n1065353216_7 = 1065353216;
                  v27 = 0;
                  n1065353216_4 = 1065353216;
                  break;
                case 4:
                  v22[4] = 1065353216;
                  v47 = 1.0;
                  memset(&v22[5], 0, 12);
                  n1065353216_2 = 0;
                  n1065353216_4 = 0;
                  break;
                case 5:
                  n1065353216_8 = 1065353216;
                  v47 = 1.0;
                  n1065353216_9 = 1065353216;
                  n1065353216_2 = 1065353216;
                  v34 = 0;
                  v35 = 0;
                  n1065353216_4 = 0;
                  break;
                default:
                  n1065353216_10 = 1065353216;
                  v47 = 1.0;
                  v42 = 0;
                  n1065353216_2 = 0;
                  v43 = 0;
                  v44 = 0;
                  n1065353216_4 = 0;
                  break;
              }
              v16 = *a1;
              v50 = 0;
              n1065353216_4 = (int)&v47;
              result = (*(int (__thiscall **)(int *, int, _DWORD))(v16 + 20))(a1, v14 + 16, *(_DWORD *)(v14 + 204));
            }
          }
          v17 = a1[21];
          if ( v17 )
          {
            result = (*(int (__thiscall **)(int))(*(_DWORD *)v17 + 44))(v17);
            if ( (result & 2) != 0 )
            {
              v18 = *(_DWORD *)(v14 + 204);
              v22[0] = 1065353216;
              memset(&v22[1], 0, 12);
              (*(void (__thiscall **)(int, int, _BYTE *, _BYTE *))(*(_DWORD *)v18 + 4))(v18, v14 + 16, v20, v21);
              result = (*(int (__thiscall **)(int, _BYTE *, _BYTE *, _DWORD *))(*(_DWORD *)a1[21] + 48))(
                         a1[21],
                         v20,
                         v21,
                         v22);
            }
          }
        }
        i_3 = i + 1;
      }
    }
  }
  return result;
}
