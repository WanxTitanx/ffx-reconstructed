// Function: sub_A27650
// Address: 0xa27650
// Size: 0x22a
// Prototype: 

int __thiscall sub_A27650(_DWORD *this)
{
  _DWORD *this_1; // ebx
  int (*__imp_printf)(const char *const, ...); // edi
  int v3; // esi
  int i; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  __int64 n2; // kr00_8
  int v9; // eax
  _DWORD *this_3; // esi
  int v11; // edi
  int *v12; // eax
  int v13; // ebx
  int v14; // eax
  void *v15; // edx
  FILE *v17; // eax
  int v18; // [esp+Ch] [ebp-20h]
  int v19; // [esp+10h] [ebp-1Ch]
  int v20; // [esp+14h] [ebp-18h]
  int v21; // [esp+20h] [ebp-Ch]
  int i_1; // [esp+24h] [ebp-8h] BYREF
  _DWORD *this_2; // [esp+28h] [ebp-4h]

  this_1 = this;
  __imp_printf = printf;
  this_2 = this;
  *(this + 58) = 1;
  do
  {
    v3 = sub_423840(this_1[68]);
    v21 = v3;
    sub_4251B0(this_1[68]);
    for ( ; v3; v21 = v3 )
    {
      if ( (unsigned __int8)sub_42B830(v3) || this_1[57] == 3 )
        break;
      sub_42C880(&i_1);
      for ( i = i_1; i_1; i = i_1 )
      {
        if ( (unsigned __int8)sub_42D050(i) || this_1[57] == 3 )
          break;
        v5 = (*(int (__thiscall **)(int))(*(_DWORD *)i_1 + 4))(i_1);
        v6 = sub_42E060(v5);
        v7 = sub_429DA0(v6);
        if ( !v7 )
        {
          __imp_printf("\t\t\tBlock\t\t:UNKNOWN TRACK TYPE\n");
          goto LABEL_28;
        }
        n2 = sub_427B10(v7);
        v9 = sub_42E0C0(v5);
        v18 = v9;
        if ( n2 == 2 || n2 == 1 )
        {
          this_3 = 0;
          if ( (_DWORD)n2 == 2 )
          {
            this_1 = this_2;
            if ( this_2[165] )
              this_3 = this_2 + 32;
          }
          else
          {
            this_1 = this_2;
            this_3 = this_2;
          }
          v11 = 0;
          if ( v9 <= 0 )
            goto LABEL_27;
          do
          {
            v12 = (int *)sub_42E0D0(v11);
            v13 = v12[2];
            v19 = *v12;
            v20 = v12[1];
            if ( this_3 )
            {
              v14 = sub_A3DEC0(v13);
              if ( !v14 )
                break;
              v15 = (void *)(v14 + 4);
              if ( v14 == -4 )
                break;
            }
            else
            {
              v15 = &unk_1984C80;
            }
            if ( !(*(int (__thiscall **)(_DWORD *, int, int, int, void *))this_2[70])(this_2 + 70, v19, v20, v13, v15)
              && this_3 )
            {
              sub_A3DF00(this_3);
            }
            ++v11;
          }
          while ( v11 < v18 );
        }
        this_1 = this_2;
LABEL_27:
        __imp_printf = printf;
LABEL_28:
        v3 = v21;
        if ( (int)sub_42C9D0(i_1, &i_1) < 0 )
        {
          __imp_printf("\t\t\tError parsing next block of cluster\n");
          v17 = __iob_func();
          return fflush(v17 + 1);
        }
      }
      v3 = sub_4238D0(v3);
    }
  }
  while ( *((_BYTE *)this_1 + 240) && this_1[57] != 3 );
  sub_A3DEA0(this_1);
  sub_A3DEA0(this_1 + 32);
  this_1[58] = 2;
  return PhyreEvent_Set((HANDLE *)this_1 + 173);
}

