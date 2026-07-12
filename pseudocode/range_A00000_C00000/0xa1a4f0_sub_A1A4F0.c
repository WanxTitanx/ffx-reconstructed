// Function: sub_A1A4F0
// Address: 0xa1a4f0
// Size: 0x1cb
// Prototype: 

int __userpurge sub_A1A4F0@<eax>(_DWORD *a1@<ecx>, int a2@<ebx>, int a3, int a4)
{
  int result; // eax

  if ( !a1[4024] || !a1[4025] )
    return 21;
  result = sub_A182F0(a1, a2, a4, a3, a4);
  if ( !result )
  {
    a1[4086] = sub_56CD50("ColorBuffer");
    a1[4087] = sub_56CD50("ShadowBuffer");
    a1[4088] = sub_56CD50("LightBuffer");
    a1[4089] = sub_56CD50("DeferredPos");
    a1[4090] = sub_56CD50("DeferredDir");
    a1[4091] = sub_56CD50("DeferredColor");
    a1[4092] = sub_56CD50("DeferredSpotAngles");
    a1[4093] = sub_56CD50("DeferredAttenParams");
    a1[4094] = sub_56CD50("DeferredShadowMask");
    a1[4095] = sub_56CD50("DeferredAmbientColor");
    a1[4096] = sub_56CD50("DeferredLightConstantBuffer");
    a1[4105] = sub_56CD50("DeferredInstantLights");
    a1[4098] = sub_56CD50("NumDeferredLights");
    a1[4097] = sub_56CD50("DeferredDirectionalLightConstantBuffer");
    a1[4099] = sub_56CD50("NumDeferredDirectionalLights");
    a1[4100] = sub_56CD50("LightingOutputBuffer");
    a1[4101] = sub_56CD50("RWLightingOutputBuffer");
    a1[4106] = sub_56CD50("RWScatteredLightingOutputBuffer");
    a1[4102] = sub_56CD50("DeferredInstantIntensity");
    a1[4103] = sub_56CD50("DeferredInstantScatteringIntensity");
    a1[4111] = sub_56CD50("DeferredLightCount");
    a1[4104] = sub_56CD50("InstantLightColorBuffer");
    return 0;
  }
  return result;
}

