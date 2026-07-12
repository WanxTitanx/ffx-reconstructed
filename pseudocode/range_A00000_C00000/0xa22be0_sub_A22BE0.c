// Function: sub_A22BE0
// Address: 0xa22be0
// Size: 0x487
// Prototype: 

int __thiscall sub_A22BE0(int *this, unsigned int a2, unsigned int a3)
{
  int v3; // ebx
  int *v4; // ebx
  int result; // eax
  int v6; // ebx
  int *v7; // ebx
  int v8; // ebx
  int *v9; // ebx
  int v10; // ebx
  int *v11; // ebx
  int v12; // ebx
  int *v13; // ebx
  int v14; // ebx
  int *v15; // ebx
  int v16; // ebx
  int *v17; // ebx
  int v18; // ebx
  int *v19; // ebx
  int v20; // ebx
  int *v21; // ebx
  int v22; // ebx
  int *v23; // ebx
  int v24; // ebx
  int *v25; // ebx

  if ( *(this + 4021) == 1 )
  {
    v20 = *(this + 4069);
    if ( v20 )
    {
      if ( !*(_BYTE *)(v20 + 4) )
      {
        v21 = *(int **)v20;
        if ( v21 )
        {
          if ( v21[7] != a2 || v21[8] != a3 )
          {
            if ( sub_596120(v21) )
            {
              result = sub_59CDD0(v21);
              if ( result )
                return result;
            }
            result = sub_4C41C0(v21, a2, a3, *v21, 0);
            if ( result )
              return result;
          }
          v22 = *(this + 4070);
          if ( v22 )
          {
            if ( !*(_BYTE *)(v22 + 4) )
            {
              v23 = *(int **)v22;
              if ( v23 )
              {
                if ( v23[7] != a2 || v23[8] != a3 )
                {
                  if ( sub_596120(v23) )
                  {
                    result = sub_59CDD0(v23);
                    if ( result )
                      return result;
                  }
                  result = sub_4C41C0(v23, a2, a3, *v23, 0);
                  if ( result )
                    return result;
                }
                v24 = *(this + 4071);
                if ( v24 )
                {
                  if ( !*(_BYTE *)(v24 + 4) )
                  {
                    v25 = *(int **)v24;
                    if ( v25 )
                    {
                      if ( v25[7] != a2 || v25[8] != a3 )
                      {
                        if ( sub_596120(v25) )
                        {
                          result = sub_59CDD0(v25);
                          if ( result )
                            return result;
                        }
                        result = sub_4C41C0(v25, a2, a3, *v25, 0);
                        if ( result )
                          return result;
                      }
                      return sub_A10590(a2, a3);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    return 1;
  }
  if ( *(this + 4021) == 2 )
  {
    v12 = *(this + 4072);
    if ( v12 )
    {
      if ( !*(_BYTE *)(v12 + 4) )
      {
        v13 = *(int **)v12;
        if ( v13 )
        {
          if ( v13[7] != a2 || v13[8] != a3 )
          {
            if ( sub_596120(v13) )
            {
              result = sub_59CDD0(v13);
              if ( result )
                return result;
            }
            result = sub_4C41C0(v13, a2, a3, *v13, 0);
            if ( result )
              return result;
          }
          v14 = *(this + 4073);
          if ( v14 )
          {
            if ( !*(_BYTE *)(v14 + 4) )
            {
              v15 = *(int **)v14;
              if ( v15 )
              {
                if ( v15[7] != a2 || v15[8] != a3 )
                {
                  if ( sub_596120(v15) )
                  {
                    result = sub_59CDD0(v15);
                    if ( result )
                      return result;
                  }
                  result = sub_4C41C0(v15, a2, a3, *v15, 0);
                  if ( result )
                    return result;
                }
                v16 = *(this + 4074);
                if ( v16 )
                {
                  if ( !*(_BYTE *)(v16 + 4) )
                  {
                    v17 = *(int **)v16;
                    if ( v17 )
                    {
                      if ( v17[7] != a2 || v17[8] != a3 )
                      {
                        if ( sub_596120(v17) )
                        {
                          result = sub_59CDD0(v17);
                          if ( result )
                            return result;
                        }
                        result = sub_4C41C0(v17, a2, a3, *v17, 0);
                        if ( result )
                          return result;
                      }
                      v18 = *(this + 4075);
                      if ( v18 )
                      {
                        if ( !*(_BYTE *)(v18 + 4) )
                        {
                          v19 = *(int **)v18;
                          if ( v19 )
                          {
                            if ( v19[7] != a2 || v19[8] != a3 )
                            {
                              if ( sub_596120(v19) )
                              {
                                result = sub_59CDD0(v19);
                                if ( result )
                                  return result;
                              }
                              result = sub_4C41C0(v19, a2, a3, *v19, 0);
                              if ( result )
                                return result;
                            }
                            return sub_A10590(a2, a3);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    return 1;
  }
  if ( *(this + 4021) != 3 )
    return sub_A10590(a2, a3);
  v3 = *(this + 4076);
  if ( !v3 )
    return 1;
  if ( *(_BYTE *)(v3 + 4) )
    return 1;
  v4 = *(int **)v3;
  if ( !v4 )
    return 1;
  if ( v4[7] != a2 || v4[8] != a3 )
  {
    if ( sub_596120(v4) )
    {
      result = sub_59CDD0(v4);
      if ( result )
        return result;
    }
    result = sub_4C41C0(v4, a2, a3, *v4, 0);
    if ( result )
      return result;
  }
  v6 = *(this + 4077);
  if ( !v6 )
    return 1;
  if ( *(_BYTE *)(v6 + 4) )
    return 1;
  v7 = *(int **)v6;
  if ( !v7 )
    return 1;
  if ( v7[7] != a2 || v7[8] != a3 )
  {
    if ( sub_596120(v7) )
    {
      result = sub_59CDD0(v7);
      if ( result )
        return result;
    }
    result = sub_4C41C0(v7, a2, a3, *v7, 0);
    if ( result )
      return result;
  }
  v8 = *(this + 4078);
  if ( !v8 )
    return 1;
  if ( *(_BYTE *)(v8 + 4) )
    return 1;
  v9 = *(int **)v8;
  if ( !v9 )
    return 1;
  if ( v9[7] != a2 || v9[8] != a3 )
  {
    if ( sub_596120(v9) )
    {
      result = sub_59CDD0(v9);
      if ( result )
        return result;
    }
    result = sub_4C41C0(v9, a2, a3, *v9, 0);
    if ( result )
      return result;
  }
  v10 = *(this + 4079);
  if ( !v10 )
    return 1;
  if ( *(_BYTE *)(v10 + 4) )
    return 1;
  v11 = *(int **)v10;
  if ( !v11 )
    return 1;
  if ( v11[7] == a2 && v11[8] == a3
    || (!sub_596120(v11) || (result = sub_59CDD0(v11)) == 0) && (result = sub_4C41C0(v11, a2, a3, *v11, 0)) == 0 )
  {
    result = RenderSurface_Recreate(*(this + 4080), a2, a3, 0);
    if ( !result )
    {
      result = RenderSurface_Recreate(*(this + 4081), a2, a3, 0);
      if ( !result )
        return sub_A10590(a2, a3);
    }
  }
  return result;
}

