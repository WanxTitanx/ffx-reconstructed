// FFX FieldMap: Load texture and shader data
void __fastcall FFX_FieldMap_LoadTexAndShaderData(FFX_System_Host *host)
{
  int PS3ShaderData; // eax

  FFX_Texture_LoadTexList(CHAR_TIDUS); /*0x645656*/
  PS3ShaderData = FFX_ShaderParser_GetPS3ShaderData(); /*0x64565b*/
  loadSpecialShaderTable(PS3ShaderData); /*0x645662*/
}