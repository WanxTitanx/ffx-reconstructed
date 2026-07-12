// Function: sub_820090
// Address: 0x820090
int sub_820090()
{
  int n2; // eax
  int v1; // eax
  char Buffer[64]; // [esp+10h] [ebp-44h] BYREF

  n2 = sub_6482B0();
  if ( !n2 )
  {
    if ( !sub_641590() && !sub_648220() )
    {
      if ( sub_641E60() )
        sub_644A80();
      sub_643AB0(0.0, 0.0, 0.0, 1.0);
      sub_643A90(0);
      sub_643AF0(1);
      sub_641FD0();
    }
    if ( sub_6481F0() )
      sub_630DE0();
    if ( sub_648120() == 1 )
    {
      if ( (FFX_Battle_GetInitReadyMask(0, 0, 0) & 0x80u) != 0 )
      {
        dword_C494CC = 0;
        return sub_630DE0();
      }
      v1 = dword_C494CC;
      if ( dword_C494CC < 0 )
      {
        if ( sub_648280() )
        {
          sub_8B5060();
          sub_648950();
          if ( !sub_648290() )
          {
            sub_648890(3);
            return sub_630DE0();
          }
        }
        else
        {
          sub_648910();
        }
        sub_648890(2);
        return sub_630DE0();
      }
      if ( dword_C494CC )
      {
        if ( !sub_6482A0() )
          return sub_630DE0();
        v1 = dword_C494CC;
      }
      if ( sub_649470(v1) )
      {
        sub_6488C0(2);
      }
      else
      {
        memset(Buffer, 0, sizeof(Buffer));
        sprintf(Buffer, "%s%d", "Description: ", dword_C494CC);
        sub_648870("FFX", "Save Data ", Buffer);
        sub_648AD0(0);
        sub_648950();
      }
      if ( ++dword_C494CC >= 200 )
      {
        dword_C494CC = -1;
        sub_8B3D60();
        sub_648890(3);
        return sub_630DE0();
      }
      return sub_630DE0();
    }
    if ( sub_648120() == 2 )
    {
      if ( sub_648240() && !sub_648090() )
      {
        if ( !sub_648250() || sub_648270() )
        {
          sub_8B3D60();
        }
        else if ( sub_8225D0() == -1 )
        {
          unk_12FB878 = 1;
          sub_647FF0();
        }
        sub_648890(3);
      }
      if ( sub_6482A0() && !sub_648090() )
      {
        sub_8B3D60();
        sub_648890(3);
      }
      n2 = sub_648210();
      if ( n2 )
      {
        n2 = sub_648090();
        if ( !n2 )
        {
          if ( unk_12FB788 )
          {
            unk_12FB788 = 0;
            return sub_648890(3);
          }
          else
          {
            return sub_648950();
          }
        }
      }
    }
    else if ( sub_648120() == 3 )
    {
      sub_6486E0();
      sub_648890(4);
      return sub_863850();
    }
    else
    {
      n2 = sub_648120();
      if ( n2 == 4 )
      {
        if ( unk_12FB878 )
        {
          n2 = sub_822510();
          if ( n2 )
          {
            if ( n2 == 1 )
            {
              n2 = sub_648890(1);
              unk_12FB878 = 0;
            }
            else if ( n2 == 2 )
            {
              sub_648890(0);
              n2 = sub_8B4E70();
              unk_12FB878 = 0;
            }
          }
        }
        else
        {
          return sub_648890(0);
        }
      }
    }
  }
  return n2;
}
