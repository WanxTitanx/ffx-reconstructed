// Function: sub_A17610
// Address: 0xa17610
// Size: 0x74
// Prototype: 

int __thiscall sub_A17610(int **this)
{
  int result; // eax
  _DWORD *v3; // edx
  int v4; // ecx
  bool v5; // zf
  int *v6; // ecx
  int *v7; // edx
  int v8; // eax

  if ( !*(this + 6) )
  {
    while ( *(this + 2) )
    {
      result = sub_443FC0(this);
      v3 = *(this + 2);
      if ( !v3 )
        break;
      v4 = v3[3];
      *(this + 5) = *(int **)(v4 + 28);
      *(this + 3) = (int *)v3[5];
      *(this + 6) = (int *)v3[7];
      v5 = *(this + 6) == 0;
      *(this + 7) = *(int **)(v4 + 140);
      result = *(v3 - 6);
      *(this + 4) = (int *)result;
      if ( !v5 )
      {
        do
        {
          v6 = *(this + 4);
          v7 = *(this + 3);
          if ( v6 != v7 )
            break;
          v8 = (int)*(this + 5);
          v5 = *(this + 6) == (int *)1;
          *(this + 6) = (int *)((char *)*(this + 6) - 1);
          *(this + 3) = (int *)((char *)v7 + v8);
          result = *v6;
          *(this + 4) = (int *)*v6;
        }
        while ( !v5 );
        if ( *(this + 6) )
          break;
      }
    }
  }
  return result;
}

