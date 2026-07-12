/*
 * Function: FFX_Menu2D_RenderSolidColorQuad
 * Address:   0x8FB150
 * Prototype: void __thiscall FFX_Menu2D_RenderSolidColorQuad(struct FFXMenu2DContext *this)
 *
 * Renders a solid color quad. Delegates to FFX_Menu_RenderEnqueue.
 *
 * Callees:
 *   FFX_Menu_RenderEnqueue
 */

void __thiscall FFX_Menu2D_RenderSolidColorQuad(struct FFXMenu2DContext *this)
{
  FFX_Menu_RenderEnqueue(this);
}
