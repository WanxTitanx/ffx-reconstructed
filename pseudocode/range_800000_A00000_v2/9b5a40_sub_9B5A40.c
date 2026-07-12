// Function: sub_9B5A40
// Address: 0x9b5a40
int __thiscall sub_9B5A40(int this, _DWORD *a2)
{
  int v2; // eax

  if ( (*(_BYTE *)(this + 216) & 3) != 0 )
  {
    *(_DWORD *)(this + 80) = *(_DWORD *)(this + 16);
    *(_DWORD *)(this + 84) = *(_DWORD *)(this + 20);
    *(_DWORD *)(this + 88) = *(_DWORD *)(this + 24);
    *(_DWORD *)(this + 92) = *(_DWORD *)(this + 28);
    *(_DWORD *)(this + 96) = *(_DWORD *)(this + 32);
    *(_DWORD *)(this + 100) = *(_DWORD *)(this + 36);
    *(_DWORD *)(this + 104) = *(_DWORD *)(this + 40);
    *(_DWORD *)(this + 108) = *(_DWORD *)(this + 44);
    *(_DWORD *)(this + 112) = *(_DWORD *)(this + 48);
    *(_DWORD *)(this + 116) = *(_DWORD *)(this + 52);
    *(_DWORD *)(this + 120) = *(_DWORD *)(this + 56);
    *(_DWORD *)(this + 124) = *(_DWORD *)(this + 60);
    *(_DWORD *)(this + 128) = *(_DWORD *)(this + 64);
    *(_DWORD *)(this + 132) = *(_DWORD *)(this + 68);
    *(_DWORD *)(this + 136) = *(_DWORD *)(this + 72);
    v2 = *(_DWORD *)(this + 76);
  }
  else
  {
    *(_DWORD *)(this + 80) = *a2;
    *(_DWORD *)(this + 84) = a2[1];
    *(_DWORD *)(this + 88) = a2[2];
    *(_DWORD *)(this + 92) = a2[3];
    *(_DWORD *)(this + 96) = a2[4];
    *(_DWORD *)(this + 100) = a2[5];
    *(_DWORD *)(this + 104) = a2[6];
    *(_DWORD *)(this + 108) = a2[7];
    *(_DWORD *)(this + 112) = a2[8];
    *(_DWORD *)(this + 116) = a2[9];
    *(_DWORD *)(this + 120) = a2[10];
    *(_DWORD *)(this + 124) = a2[11];
    *(_DWORD *)(this + 128) = a2[12];
    *(_DWORD *)(this + 132) = a2[13];
    *(_DWORD *)(this + 136) = a2[14];
    v2 = a2[15];
  }
  *(_DWORD *)(this + 140) = v2;
  *(_DWORD *)(this + 144) = *(_DWORD *)(this + 320);
  *(_DWORD *)(this + 148) = *(_DWORD *)(this + 324);
  *(_DWORD *)(this + 152) = *(_DWORD *)(this + 328);
  *(_DWORD *)(this + 156) = *(_DWORD *)(this + 332);
  *(_DWORD *)(this + 160) = *(_DWORD *)(this + 336);
  *(_DWORD *)(this + 164) = *(_DWORD *)(this + 340);
  *(_DWORD *)(this + 168) = *(_DWORD *)(this + 344);
  *(_DWORD *)(this + 172) = *(_DWORD *)(this + 348);
  *(_DWORD *)(this + 16) = *a2;
  *(_DWORD *)(this + 20) = a2[1];
  *(_DWORD *)(this + 24) = a2[2];
  *(_DWORD *)(this + 28) = a2[3];
  *(_DWORD *)(this + 32) = a2[4];
  *(_DWORD *)(this + 36) = a2[5];
  *(_DWORD *)(this + 40) = a2[6];
  *(_DWORD *)(this + 44) = a2[7];
  *(_DWORD *)(this + 48) = a2[8];
  *(_DWORD *)(this + 52) = a2[9];
  *(_DWORD *)(this + 56) = a2[10];
  *(_DWORD *)(this + 60) = a2[11];
  *(_DWORD *)(this + 64) = a2[12];
  *(_DWORD *)(this + 68) = a2[13];
  *(_DWORD *)(this + 72) = a2[14];
  *(_DWORD *)(this + 76) = a2[15];
  return sub_9B6390();
}
