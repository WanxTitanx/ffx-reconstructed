/*
 * Function: FFX_Menu2D_RenderColorQuad
 * Address:   0x8FD390
 * Prototype: void __cdecl FFX_Menu2D_RenderColorQuad(int a1, int n32, int a3, int a4, int a5, int a6)
 *
 * Renders a color quad. Delegates to FFX_Menu_RenderEnqueue.
 *
 * Callees:
 *   FFX_Menu_RenderEnqueue
 */

void __cdecl FFX_Menu2D_RenderColorQuad(int a1, int n32, int a3, int a4, int a5, int a6)
{
  FFX_Menu_RenderEnqueue((struct FFXMenu2DContext *)HIBYTE(a6));
}
