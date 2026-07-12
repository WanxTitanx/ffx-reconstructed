// Function: sub_9C2A00
// Address: 0x9c2a00
void __userpurge sub_9C2A00(
        _DWORD *a1@<ecx>,
        char a2@<efl>,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int *a9,
        int a10,
        int a11)
{
  int *v12; // ecx
  int v13; // eax
  int v14; // ebx
  int v15; // edi
  int v16; // ebx
  int v17; // edi
  int v18; // [esp-Ch] [ebp-14h]
  int v19; // [esp-Ch] [ebp-14h]
  int v20; // [esp+4h] [ebp-4h]

  v12 = a9;
  if ( a9[11] )
  {
    v13 = 0;
    v20 = 0;
    if ( (a9[15] & 0x100) != 0 )
    {
      if ( a9[5] > 0 )
      {
        do
        {
          v14 = a1[2];
          v15 = 0;
          if ( v14 > 0 )
          {
            do
            {
              v18 = a1[4] + 192 * *(_DWORD *)(a1[19] + 4 * v15);
              sub_9BF430(a2, *(__m128 **)(v18 + 128), *(__m128 **)(v18 + 132), (__m128 *)v18);
              ++v15;
            }
            while ( v15 < v14 );
            v13 = v20;
            v12 = a9;
          }
          v20 = ++v13;
        }
        while ( v13 < v12[5] );
      }
    }
    else if ( a9[5] > 0 )
    {
      do
      {
        v16 = a1[2];
        v17 = 0;
        if ( v16 > 0 )
        {
          do
          {
            v19 = a1[4] + 192 * *(_DWORD *)(a1[19] + 4 * v17);
            sub_9BF0A0(a2, *(float **)(v19 + 128), *(float **)(v19 + 132), (float *)v19);
            ++v17;
          }
          while ( v17 < v16 );
          v13 = v20;
          v12 = a9;
        }
        v20 = ++v13;
      }
      while ( v13 < v12[5] );
    }
  }
}
