/*
 * Function: FFX_Menu2D_RenderEnqueueQuad
 * Address:   0x8EC250
 * Prototype: int __cdecl FFX_Menu2D_RenderEnqueueQuad(
 *                int a1, int a2, int a3, int a4, int a5,
 *                int n17, int a7, struct FFXMenu2DContext *a8)
 *
 * Enqueues a quad for rendering. Delegates to FFX_Menu_RenderEnqueue.
 *
 * Callees:
 *   FFX_Menu_RenderEnqueue
 */

int __cdecl FFX_Menu2D_RenderEnqueueQuad(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int n17,
        int a7,
        struct FFXMenu2DContext *a8)
{
  FFX_Menu_RenderEnqueue(a8);
  return a1;
}
