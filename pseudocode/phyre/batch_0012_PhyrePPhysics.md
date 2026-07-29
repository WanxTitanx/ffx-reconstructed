# FFX.exe Decompilation — Batch 12 (Phyre_PPhysics WorldSetup)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** 37 (Phyre_PPhysics_WorldSetup_* — factory dispatch functions for all physics shapes)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

This batch covers all 37 `Phyre_PPhysics_WorldSetup_*` functions in FFX.exe — the **physics shape factory dispatch layer** of PhyreEngine. Every function follows an identical pattern:

1. **Get** a physics object from a scripting accessor (`PhyreScripting_Get_<Shape>`)
2. **Copy** data from the scripting object into an output buffer via one of 3 copy primitives
3. **Return** the result

All 37 functions are single basic block (no branches), zero strings, 27-101 bytes each. They are NOT physics simulation code — they are the **scripting binding layer** that bridges Lua/PEngine scripting to the Bullet Physics C++ objects.

### The 3 Copy Primitives

| Primitive | Address | Copies | Used By |
|-----------|---------|--------|---------|
| `Phyre_physics_worldSetup(a2, src)` | 0x5E3B60 | 88-108 bytes (field-by-field at offsets +88..+108) | 22 functions (primary) |
| `Phyre_transformData_copyShallow(dst, src)` | 0x5E34E0 | 264 bytes (shallow float copy) | 4 functions |
| `Phyre_vertexData_copy(dst, src)` | 0x5E3950 | 220 bytes (vertex data) | 3 functions |
| `Phyre_physicsObject_copyDeep(dst, src)` | 0x5E3DC0 | Deep copy (entire physics object) | 2 functions |
| `Phyre_physicsState_reset(dst, src)` | 0x5E3D40 | State reset | 1 function |

---

### Shape Inheritance Architecture

The 6 shape families (Box, Capsule, Cylinder, Plane, Sphere, Mesh) form a **3-tier inheritance** in the factory dispatch:

```
Tier 1: <Shape>         — shallow pointer copy (3-4 DWORDs: *a2 = *src)
Tier 2: <Shape>Base     — physics_worldSetup + 5 copy fields (+88..+108)
Tier 3: <Shape>Bullet   — physics_worldSetup + 5-6 copy fields (+88..+108)
```

Additional types (Interface, RigidBody, Shape, TaperedCapsule, TaperedCylinder, World, CharacterCamera, Material, RaycastResult) follow similar patterns but with unique copy logic.

---

## Part 1: Box Family (4 functions)

### Phyre_PPhysics_WorldSetup_Box (0x5feba0, 65 bytes)
```c
int __stdcall Phyre_PPhysics_WorldSetup_Box(_DWORD *a1, int a2)
{
  int v2 = Phyre_PScriptAccessors_PObjectAccessor_PPhysicsBox_Get(a1);
  Phyre_physics_worldSetup(a2, v2);
  *(_DWORD *)(a2 + 88) = *(_DWORD *)(v2 + 88);
  *(float *)(a2 + 92) = *(float *)(v2 + 92);
  *(float *)(a2 + 96) = *(float *)(v2 + 96);
  *(float *)(a2 + 100) = *(float *)(v2 + 100);
  int result = *(_DWORD *)(v2 + 108);
  *(_DWORD *)(a2 + 108) = result;
  return result;
}
```
- **Vtable:** 0xB39CC0
- **Pattern:** `physics_worldSetup` + 5 field copies (offsets 88, 92, 96, 100, 108)

### Phyre_PPhysics_WorldSetup_BoxBase (0x5febf0, 59 bytes)
```c
int __stdcall Phyre_PPhysics_WorldSetup_BoxBase(_DWORD *a1, int a2)
{
  int v2 = Phyre_PScriptAccessors_PObjectAccessor_PPhysicsBoxBase_Get(a1);
  int result = Phyre_physics_worldSetup(a2, v2);
  *(_DWORD *)(a2 + 88) = *(_DWORD *)(v2 + 88);
  *(float *)(a2 + 92) = *(float *)(v2 + 92);
  *(float *)(a2 + 96) = *(float *)(v2 + 96);
  *(float *)(a2 + 100) = *(float *)(v2 + 100);
  return result;  // Note: does NOT copy +108 (unlike Box)
}
```
- **Vtable:** 0xB39AC8
- **Pattern:** `physics_worldSetup` + 4 field copies (no +108)

### Phyre_PPhysics_WorldSetup_BoxBullet (0x5fec30, 65 bytes)
```c
// Identical to Box — same field layout, same accessor pattern
```
- **Vtable:** 0xB39BC0
- **Accessor:** `PObjectAccessor_PPhysicsBoxBullet_Get`

### Phyre_PPhysics_WorldSetup_BoxBullet2 (0x5fec80, 71 bytes)
```c
// Same as BoxBullet but ALSO copies +104
```
- **Vtable:** 0xB3A5B0
- **Extra field:** `a2[26] = v2[26]` (+104) — additional DWORD beyond Box/BoxBullet

---

## Part 2: Capsule Family (3 functions)

### Phyre_PPhysics_WorldSetup_Capsule (0x5fecd0, 65 bytes)
```c
int __stdcall Phyre_PPhysics_WorldSetup_Capsule(_DWORD *a1, int a2)
{
  int v2 = Phyre_PScriptAccessors_PObjectAccessor_PPhysics_Character_Get(a1);
  Phyre_physics_worldSetup(a2, v2);
  *(_DWORD *)(a2 + 88) = *(_DWORD *)(v2 + 88);
  *(float *)(a2 + 92) = *(float *)(v2 + 92);
  *(float *)(a2 + 96) = *(float *)(v2 + 96);
  *(float *)(a2 + 100) = *(float *)(v2 + 100);
  int result = *(_DWORD *)(v2 + 104);
  *(_DWORD *)(a2 + 104) = result;
  return result;
}
```
- **Vtable:** 0xB3A3B0
- **Note:** Accessor named "PPhysics_Character" — Capsule is character controller shape

### Phyre_PPhysics_WorldSetup_CapsuleBase (0x5fed20, 71 bytes)
```c
// Same as Capsule but ALSO copies +108 (BoxBullet2-equivalent)
```
- **Vtable:** 0xB3A4B0
- **Accessor:** `PObjectAccessor_PPhysics_Character2_Get`

### Phyre_PPhysics_WorldSetup_CapsuleBullet (0x5fed70, 27 bytes)
```c
int __stdcall Phyre_PPhysics_WorldSetup_CapsuleBullet(_DWORD *a1, int a2)
{
  int v2 = Phyre_PScriptAccessors_PObjectAccessor_PPhysicsWorldStats_Get(a1);
  return Phyre_transformData_copy(a2, v2);
}
```
- **Vtable:** 0xB3B078
- **Pattern:** DIFFERENT — uses `Phyre_transformData_copy` (264-byte copy), not `physics_worldSetup`
- **Note:** Portal to a completely different data path (world stats)

---

## Part 3: Cylinder Family (3 functions)

### Phyre_PPhysics_WorldSetup_Cylinder (0x5fee00, 27 bytes)
```c
float *__stdcall Phyre_PPhysics_WorldSetup_Cylinder(_DWORD *a1, float *a2)
{
  int CharacterControllerBase = PhyreScripting_Get_CharacterControllerBase(a1);
  return Phyre_transformData_copyShallow(a2, CharacterControllerBase);
}
```
- **Vtable:** 0xB3B170
- **Pattern:** `transformData_copyShallow` (264-byte shallow copy)

### Phyre_PPhysics_WorldSetup_CylinderBase (0x5fee20, 101 bytes)
```c
float *__stdcall Phyre_PPhysics_WorldSetup_CylinderBase(_DWORD *a1, int a2)
{
  int CharacterControllerBullet = PhyreScripting_Get_CharacterControllerBullet(a1);
  Phyre_transformData_copyShallow((float *)a2, CharacterControllerBullet);
  *(_DWORD *)(a2 + 268) = *(_DWORD *)(CharacterControllerBullet + 268);
  *(_DWORD *)(a2 + 272) = *(_DWORD *)(CharacterControllerBullet + 272);
  *(_DWORD *)(a2 + 276) = *(_DWORD *)(CharacterControllerBullet + 276);
  *(_DWORD *)(a2 + 280) = *(_DWORD *)(CharacterControllerBullet + 280);
  return Phyre_PMatrix4_copy16f((float *)(a2 + 284), (float *)(CharacterControllerBullet + 284));
}
```
- **Vtable:** 0xB3B268
- **Pattern:** `transformData_copyShallow` + 4 extra DWORDs (268-280) + full 4x4 matrix copy (284+)
- **Largest in Cylinder family** (101 bytes, 3 callees)

### Phyre_PPhysics_WorldSetup_CylinderBullet (0x5fee90, 65 bytes)
```c
// physics_worldSetup + 4 field copies (+88..+104) — reverts to physics_worldSetup pattern
```
- **Vtable:** 0xB3A2B0
- **Accessor:** `PObjectAccessor_POmniLight_Get` (misleading name — returns cylinder bullet data)
- **Note:** Different accessor family from Cylinder/CylinderBase

---

## Part 4: Plane Family (3 functions)

### Phyre_PPhysics_WorldSetup_Plane (0x5ff110, 37 bytes)
```c
int __stdcall Phyre_PPhysics_WorldSetup_Plane(_DWORD *a1, _DWORD *a2)
{
  _DWORD *Model = (_DWORD *)PhyreScripting_Get_Model(a1);
  *a2 = *Model;
  a2[1] = Model[1];
  int result = Model[2];
  a2[2] = result;
  return result;
}
```
- **Vtable:** 0xB3AF90
- **Pattern:** Shallow pointer copy (3 DWORDs)
- **Note:** Copies from "Model" accessor — Plane is a lightweight handle

### Phyre_PPhysics_WorldSetup_PlaneBase (0x5ff140, 71 bytes)
```c
// physics_worldSetup + 5 field copies (+88..+108, same as Box)
```
- **Vtable:** 0xB3AAA8

### Phyre_PPhysics_WorldSetup_PlaneBullet (0x5ff190, 65 bytes)
```c
// physics_worldSetup + 4 field copies (+88..+104, no +108)
```
- **Vtable:** 0xB3A8A8

---

## Part 5: Sphere Family (3 functions)

### Phyre_PPhysics_WorldSetup_Sphere (0x5ff330, 53 bytes)
```c
int __stdcall Phyre_PPhysics_WorldSetup_Sphere(_DWORD *a1, int a2)
{
  int Sphere = PhyreScripting_Get_Sphere(a1);
  Phyre_physics_worldSetup(a2, Sphere);
  *(_DWORD *)(a2 + 88) = *(_DWORD *)(Sphere + 88);
  *(float *)(a2 + 92) = *(float *)(Sphere + 92);
  int result = *(_DWORD *)(Sphere + 96);
  *(_DWORD *)(a2 + 96) = result;
  return result;
}
```
- **Vtable:** 0xB399D0
- **Pattern:** `physics_worldSetup` + 2 field copies (+88, +92, +96) — simplest Bullet-tier shape

### Phyre_PPhysics_WorldSetup_SphereBase (0x5ff370, 47 bytes)
```c
// physics_worldSetup + 1 field copy (+88, +92) — only 2 fields
```
- **Vtable:** 0xB397D0

### Phyre_PPhysics_WorldSetup_SphereBullet (0x5ff3a0, 53 bytes)
```c
// Identical to Sphere (physics_worldSetup + 88, 92, 96)
```
- **Vtable:** 0xB398D0

---

## Part 6: Mesh Family (3 functions)

### Phyre_PPhysics_WorldSetup_Mesh (0x5ff010, 37 bytes)
```c
int __stdcall Phyre_PPhysics_WorldSetup_Mesh(_DWORD *a1, _DWORD *a2)
{
  _DWORD *Material = (_DWORD *)PhyreScripting_Get_Material(a1);
  *a2 = *Material;
  a2[1] = Material[1];
  int result = Material[2];
  a2[2] = result;
  return result;
}
```
- **Vtable:** 0xB39438
- **Pattern:** Shallow pointer copy (3 DWORDs)
- **Accessor:** `PhyreScripting_Get_Material` (Mesh Tier 1 maps to Material accessor)

### Phyre_PPhysics_WorldSetup_MeshBase (0x5ff040, 65 bytes)
```c
// physics_worldSetup + 5 field copies (+88..+108, same as Box tier)
```
- **Vtable:** 0xB39FB8

### Phyre_PPhysics_WorldSetup_MeshBullet (0x5ff090, 47 bytes)
```c
// physics_worldSetup + 2 field copies (+88, +92) — simplified
```
- **Vtable:** 0xB39DB8

---

## Part 7: Interface Family (3 functions)

### Phyre_PPhysics_WorldSetup_Interface (0x5feee0, 59 bytes)
```c
// physics_worldSetup + 3 field copies (+88, +92, +96, +100; no +104/+108)
```
- **Vtable:** 0xB3A0B0

### Phyre_PPhysics_WorldSetup_InterfaceBase (0x5fef20, 65 bytes)
```c
// physics_worldSetup + 4 field copies (+88..+104, no +108)
```
- **Vtable:** 0xB3A1B0

### Phyre_PPhysics_WorldSetup_InterfaceBullet (0x5fef70, 43 bytes)
```c
int __stdcall Phyre_PPhysics_WorldSetup_InterfaceBullet(_DWORD *a1, _DWORD *a2)
{
  _DWORD *InterfaceBase = (_DWORD *)PhyreScripting_Get_InterfaceBase(a1);
  *a2 = *InterfaceBase;
  a2[1] = InterfaceBase[1];
  a2[2] = InterfaceBase[2];
  int result = InterfaceBase[3];
  a2[3] = result;
  return result;
}
```
- **Vtable:** 0xB3B7F0
- **Pattern:** Shallow pointer copy (4 DWORDs)
- **Accessor:** `PhyreScripting_Get_InterfaceBase` (Tier 1 of Interface maps to InterfaceBase accessor)

---

## Part 8: Shape Family (3 functions)

### Phyre_PPhysics_WorldSetup_Shape (0x5ff290, 59 bytes)
```c
int __stdcall Phyre_PPhysics_WorldSetup_Shape(_DWORD *a1, int a2)
{
  int RigidBodyBullet = PhyreScripting_Get_RigidBodyBullet(a1);
  Phyre_vertexData_copy((float *)a2, RigidBodyBullet);
  *(_DWORD *)(a2 + 220) = *(_DWORD *)(RigidBodyBullet + 220);
  int result = *(_DWORD *)(RigidBodyBullet + 224);
  *(_DWORD *)(a2 + 224) = result;
  return result;
}
```
- **Vtable:** 0xB396D8
- **Pattern:** `vertexData_copy` (220 bytes) + 2 field copies (+220, +224)
- **Note:** Uses `vertexData_copy`, not `physics_worldSetup` — different struct layout

### Phyre_PPhysics_WorldSetup_ShapeBase (0x5ff2d0, 41 bytes)
```c
// physics_worldSetup + 1 field copy (+88 only)
```
- **Vtable:** 0xB396D8

### Phyre_PPhysics_WorldSetup_ShapeBullet (0x5ff300, 41 bytes)
```c
// physics_worldSetup + 1 field copy (+88 only) — identical to ShapeBase
```
- **Vtable:** 0xB395D8

---

## Part 9: RigidBody Family (3 functions)

### Phyre_PPhysics_WorldSetup_RigidBody (0x5ff1e0, 71 bytes)
```c
// physics_worldSetup + 5 field copies (+88..+108, like Box)
```
- **Vtable:** 0xB3A9A8

### Phyre_PPhysics_WorldSetup_RigidBodyBase (0x5ff230, 59 bytes)
```c
int __stdcall Phyre_PPhysics_WorldSetup_RigidBodyBase(_DWORD *a1, int a2)
{
  int RigidBody = PhyreScripting_Get_RigidBody(a1);
  Phyre_vertexData_copy((float *)a2, RigidBody);
  *(_DWORD *)(a2 + 220) = *(_DWORD *)(RigidBody + 220);
  int result = *(_DWORD *)(RigidBody + 224);
  *(_DWORD *)(a2 + 224) = result;
  return result;
}
```
- **Vtable:** 0xB3AEA8
- **Pattern:** `vertexData_copy` + 2 field copies (+220, +224)

### Phyre_PPhysics_WorldSetup_RigidBodyBullet (0x5ff270, 27 bytes)
```c
float *__stdcall Phyre_PPhysics_WorldSetup_RigidBodyBullet(_DWORD *a1, float *a2)
{
  int RigidBodyBase = PhyreScripting_Get_RigidBodyBase(a1);
  return Phyre_vertexData_copy(a2, RigidBodyBase);
}
```
- **Vtable:** 0xB3AC90
- **Pattern:** Pure `vertexData_copy` — shallowest in the family

---

## Part 10: Tapered Shapes (2 functions)

### Phyre_PPhysics_WorldSetup_TaperedCapsule (0x5ff3e0, 71 bytes)
```c
// physics_worldSetup + 6 field copies (+88, 92, 96, 100, 104, 108) — FULL set
```
- **Vtable:** 0xB3A7A8
- **Note:** Copies ALL 6 DWORDs — the most complete field copy pattern

### Phyre_PPhysics_WorldSetup_TaperedCylinder (0x5ff430, 71 bytes)
```c
// physics_worldSetup + 6 field copies (+88..+108) — identical to TaperedCapsule
```
- **Vtable:** 0xB3A6A8

---

## Part 11: World Family (3 functions)

### Phyre_PPhysics_WorldSetup_World (0x5ff480, 27 bytes)
```c
_DWORD *__stdcall Phyre_PPhysics_WorldSetup_World(_DWORD *a1, _DWORD *a2)
{
  char *World = (char *)PhyreScripting_Get_World(a1);
  return Phyre_physicsObject_copyDeep(a2, World);
}
```
- **Vtable:** 0xB3B708
- **Pattern:** Deep copy via `physicsObject_copyDeep`

### Phyre_PPhysics_WorldSetup_WorldBase (0x5ff4a0, 27 bytes)
```c
float *__stdcall Phyre_PPhysics_WorldSetup_WorldBase(_DWORD *a1, float *a2)
{
  float *WorldBase = (float *)PhyreScripting_Get_WorldBase(a1);
  return Phyre_physicsState_reset(a2, WorldBase);
}
```
- **Vtable:** 0xB3B538
- **Pattern:** State reset via `physicsState_reset` — unique in this batch

### Phyre_PPhysics_WorldSetup_WorldBullet (0x5ff4c0, 27 bytes)
```c
// Identical to World — deep copy via physicsObject_copyDeep
```
- **Vtable:** 0xB3B620

---

## Part 12: Special Types (3 functions)

### Phyre_PPhysics_WorldSetup_CharacterCamera (0x5fed90, 101 bytes) ⭐
```c
float *__stdcall Phyre_PPhysics_WorldSetup_CharacterCamera(_DWORD *a1, int a2)
{
  int v2 = Phyre_PScriptAccessors_PObjectAccessor_PPhysicsRaycastResult_Get(a1);
  Phyre_transformData_copyShallow((float *)a2, v2);
  *(_DWORD *)(a2 + 268) = *(_DWORD *)(v2 + 268);
  *(_DWORD *)(a2 + 272) = *(_DWORD *)(v2 + 272);
  *(_DWORD *)(a2 + 276) = *(_DWORD *)(v2 + 276);
  *(_DWORD *)(a2 + 280) = *(_DWORD *)(v2 + 280);
  return Phyre_PMatrix4_copy16f((float *)(a2 + 284), (float *)(v2 + 284));
}
```
- **Vtable:** 0xB3B360
- **Accessor:** `PObjectAccessor_PPhysicsRaycastResult_Get` (NOT camera!)
- **Pattern:** Same as CylinderBase — `transformData_copyShallow` + 4 DWORDs + full matrix copy
- **Struct:** 284+ bytes with embedded 4x4 matrix at offset +284

### Phyre_PPhysics_WorldSetup_Material (0x5fefa0, 98 bytes) ⭐
```c
int __stdcall Phyre_PPhysics_WorldSetup_Material(_DWORD *a1, _DWORD *a2)
{
  _DWORD *InterfaceBullet = (_DWORD *)PhyreScripting_Get_InterfaceBullet(a1);
  *a2 = *InterfaceBullet;
  a2[1] = InterfaceBullet[1];
  a2[2] = InterfaceBullet[2];
  a2[3] = InterfaceBullet[3];
  a2[4] = InterfaceBullet[4];
  a2[5] = InterfaceBullet[5];
  a2[6] = InterfaceBullet[6];
  Phyre_physics_worldStep(a2 + 7, InterfaceBullet + 7);
  int result = InterfaceBullet[9];
  a2[9] = result;
  qmemcpy(a2 + 10, InterfaceBullet + 10, 0x24u);
  return result;
}
```
- **Vtable:** 0xB3B8E0
- **Pattern:** Most complex — 7 DWORD pointer copy + `physics_worldStep` + 0x24 (36) byte qmemcpy
- **Constants:** 0x28 (40 = 10 DWORDS), 0x9, 0x24 (36 bytes)
- **Note:** Material is the MOST complex WorldSetup function (98 bytes, 5 constants)

### Phyre_PPhysics_WorldSetup_RaycastResult (0x5ff4e0, 81 bytes)
```c
int __stdcall Phyre_PPhysics_WorldSetup_RaycastResult(_DWORD *a1, int a2)
{
  int RaycastResult = PhyreScripting_Get_RaycastResult(a1);
  int v3 = *(_DWORD *)(RaycastResult + 32);
  *(float *)a2 = *(float *)RaycastResult;
  *(_DWORD *)(a2 + 32) = v3;
  int result = *(_DWORD *)(RaycastResult + 36);
  *(float *)(a2 + 4) = *(float *)(RaycastResult + 4);
  *(_DWORD *)(a2 + 36) = result;
  *(float *)(a2 + 8) = *(float *)(RaycastResult + 8);
  *(float *)(a2 + 12) = *(float *)(RaycastResult + 12);
  *(float *)(a2 + 16) = *(float *)(RaycastResult + 16);
  *(float *)(a2 + 20) = *(float *)(RaycastResult + 20);
  *(float *)(a2 + 24) = *(float *)(RaycastResult + 24);
  *(float *)(a2 + 28) = *(float *)(RaycastResult + 28);
  return result;
}
```
- **Vtable:** 0xB3B450
- **Pattern:** Raw field-by-field copy (32 bytes: 8 floats + 2 DWORDs)
- **Struct:**
  ```
  +0:  float origin.x
  +4:  float origin.y
  +8:  float origin.z
  +12: float direction.x
  +16: float direction.y
  +20: float direction.z
  +24: float (unknown)
  +28: float (unknown)
  +32: DWORD hitId
  +36: DWORD hitType
  ```
- **Note:** UNIQUE pattern — the only function that copies raw floats field-by-field

---

## Summary Tables

### Size Distribution

| Bucket | Range | Count |
|--------|-------|-------|
| Tiny | < 32 bytes | 8 |
| Small | 32 - 63 | 20 |
| Medium | 64 - 101 | 9 |
| Large | >= 102 | 0 |

### Copy Primitive Distribution

| Primitive | Count | Functions |
|-----------|-------|-----------|
| `physics_worldSetup` + fields | 22 | Box, BoxBase, BoxBullet, BoxBullet2, Capsule, CapsuleBase, CylinderBullet, Interface, InterfaceBase, PlaneBase, PlaneBullet, Sphere, SphereBase, SphereBullet, MeshBase, MeshBullet, Model, RigidBody, ShapeBase, ShapeBullet, TaperedCapsule, TaperedCylinder |
| `transformData_copyShallow` | 4 | Cylinder, CylinderBase, CharacterCamera, CapsuleBullet |
| `vertexData_copy` | 3 | RigidBodyBase, RigidBodyBullet, Shape |
| Shallow pointer copy (3-4 DW) | 4 | Plane, Mesh, InterfaceBullet, Material (partial) |
| `physicsObject_copyDeep` | 2 | World, WorldBullet |
| `physicsState_reset` | 1 | WorldBase |
| Field-by-field | 1 | RaycastResult |

### Vtable Addresses

| Function | Vtable |
|----------|--------|
| Box | 0xB39CC0 |
| BoxBase | 0xB39AC8 |
| BoxBullet | 0xB39BC0 |
| BoxBullet2 | 0xB3A5B0 |
| Capsule | 0xB3A3B0 |
| CapsuleBase | 0xB3A4B0 |
| CapsuleBullet | 0xB3B078 |
| CharacterCamera | 0xB3B360 |
| Cylinder | 0xB3B170 |
| CylinderBase | 0xB3B268 |
| CylinderBullet | 0xB3A2B0 |
| Interface | 0xB3A0B0 |
| InterfaceBase | 0xB3A1B0 |
| InterfaceBullet | 0xB3B7F0 |
| Material | 0xB3B8E0 |
| Mesh | 0xB39438 |
| MeshBase | 0xB39FB8 |
| MeshBullet | 0xB39DB8 |
| Model | 0xB39EB8 |
| Plane | 0xB3AF90 |
| PlaneBase | 0xB3AAA8 |
| PlaneBullet | 0xB3A8A8 |
| RaycastResult | 0xB3B450 |
| RigidBody | 0xB3A9A8 |
| RigidBodyBase | 0xB3AEA8 |
| RigidBodyBullet | 0xB3AC90 |
| Shape | 0xB396D8 |
| ShapeBase | 0xB396D8 |
| ShapeBullet | 0xB395D8 |
| Sphere | 0xB399D0 |
| SphereBase | 0xB397D0 |
| SphereBullet | 0xB398D0 |
| TaperedCapsule | 0xB3A7A8 |
| TaperedCylinder | 0xB3A6A8 |
| World | 0xB3B708 |
| WorldBase | 0xB3B538 |
| WorldBullet | 0xB3B620 |

### Key Callers

| Callee | Address | Called By |
|--------|---------|-----------|
| `Phyre_physics_worldSetup` | 0x5E3B60 | 22 functions (core dispatch) |
| `Phyre_physicsObject_copyDeep` | 0x5E3DC0 | World, WorldBullet |
| `Phyre_physicsState_reset` | 0x5E3D40 | WorldBase |
| `Phyre_physics_worldStep` | 0x5E2F00 | Material |
| `Phyre_transformData_copyShallow` | 0x5E34E0 | Cylinder, CylinderBase, CharacterCamera |
| `Phyre_vertexData_copy` | 0x5E3950 | RigidBodyBase, RigidBodyBullet, Shape |
| `Phyre_PMatrix4_copy16f` | 0x453420 | CylinderBase, CharacterCamera |

---

## Key Findings

1. **Zero physics logic** — All 37 functions are factory dispatch wrappers. No collision detection, no solver, no constraint logic. The actual Bullet Physics simulation lives in the `Phyre_physics_*` callees.

2. **3-tier inheritance for each shape** — Every physics shape (Box, Capsule, Cylinder, etc.) has 3 WorldSetup functions corresponding to the PhyreEngine type hierarchy: `<Shape>` (Tier 1, shallow), `<Shape>Base` (Tier 2, medium), `<Shape>Bullet` (Tier 3, full). This mirrors the class hierarchy `PPhysicsShape → PPhysicsShapeBullet → btCollisionShape`.

3. **Struct layout consistency** — All `physics_worldSetup` calls share the same field layout at offsets +88 through +108 (6 DWORDs). This is the physics shape parameter block. Different shapes copy different subsets of these 6 fields:
   - Box family: copies 88, 92, 96, 100, 108 (5 fields, skips 104)
   - Capsule: copies 88, 92, 96, 100, 104 (5 fields, skips 108)
   - Sphere: copies 88, 92, 96 (3 fields)
   - Tapered shapes: copies all 6 (88-108)

4. **Character controller = Capsule** — The Capsule family accessors are named `PPhysics_Character` / `PPhysics_Character2`, confirming capsule colliders are used for character controllers in PhyreEngine.

5. **Accessor naming is NOT shape-named** — Several WorldSetup functions call accessors named after DIFFERENT types:
   - `Plane` calls `PhyreScripting_Get_Model`
   - `Mesh` calls `PhyreScripting_Get_Material`
   - `CylinderBullet` calls `PObjectAccessor_POmniLight_Get`
   - `CapsuleBullet` calls `PObjectAccessor_PPhysicsWorldStats_Get`
   These are likely shared scripting bindings where the accessor returns the correct type cast.

6. **Material is the most complex** — `WorldSetup_Material` (98 bytes) has 5 constants, 3 copy patterns (DWORD copy + worldStep + qmemcpy), and is the only function using `Phyre_physics_worldStep`.

7. **RaycastResult has unique struct** — 32 bytes of raw float data (origin, direction, + 2 unknown floats) + 2 DWORDs at offset +32/+36 (hit ID and type). Field-by-field copy is unique in the batch.

---

## Next Batches

- Batch 13: Phyre_PInput_Pad/Keyboard/Mouse/Touch (~150 functions)
- Batch 14: Phyre_PRendering (render pipeline, D3D11)
- Batch 15: Phyre_PSceneNode (~90 functions)
- Batch 16: Remaining Phyre families (PPostProcessing, PAudio, etc.)
