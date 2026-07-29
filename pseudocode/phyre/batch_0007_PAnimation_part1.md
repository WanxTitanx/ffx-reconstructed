# FFX.exe Decompilation — Batch 7 (Phyre_PAnimation Part 1)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** 25 (Phyre_PAnimation family — class descriptors, destructors, getters)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

This batch covers the Phyre_PAnimation type registration layer — class descriptor registration, destructor variants, and simple accessors for `PAnimationSlotArray`, `PAnimationSlotListIndex`, `PAnimationTarget`, and `PAnimationChannelTarget`. These are mostly template-generated boilerplate following the standard PhyreEngine patterns.

---

## Functions Decompiled

### GetClassName Thunks (6 bytes each)

#### Phyre_PAnimationSlotArray_GetClassName (0x508040, 6 bytes)
```c
const char *Phyre_PAnimationSlotArray_GetClassName()
{
  return "PAnimationSlotArray";
}
```

#### Phyre_PAnimationSlotListIndex_GetClassName (0x508050, 6 bytes)
```c
const char *Phyre_PAnimationSlotListIndex_GetClassName()
{
  return "PAnimationSlotListIndex";
}
```

#### Phyre_PAnimationSlotArray_GetClassName_B (0x508b10, 6 bytes)
```c
const char *Phyre_PAnimationSlotArray_GetClassName_B()
{
  return "PAnimationSlotArray";
}
```

#### Phyre_PAnimationSlotListIndex_GetClassName_B (0x508b20, 6 bytes)
```c
const char *Phyre_PAnimationSlotListIndex_GetClassName_B()
{
  return "PAnimationSlotListIndex";
}
```

---

### Class Descriptor Registration

#### Phyre_PAnimationTarget_RegisterDescriptor (0x5081e0, 145 bytes)
```c
PhyrePClassDescriptor *__thiscall Phyre_PAnimationTarget_RegisterDescriptor(PhyrePClassDescriptor *this)
{
  DefaultPool = Phyre_GetDefaultPool();
  Singleton = Phyre_PNamespace_GetSingleton();
  Phyre_PClassDescriptor_ctor(this, Singleton, "PAnimationSlotArray", 4, 4, DefaultPool, 0);
  *((_DWORD *)this + 36) |= 2u;
  this->vfptr = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationSlotArray>::vftable;
  Phyre_PClassDescriptor_SetField64(this, &val__23);
  Phyre_PClassDescriptor_SetField68(this, &val__24);
  Phyre_PClassDescriptor_SetField6C(this, &val__25);
}
```
- **Class:** `PAnimationSlotArray` (size=4, align=4)
- **Vtable:** 0xB25294
- **Purpose:** Standard class descriptor registration

#### Phyre_PAnimationSlotArray_RegisterDescriptor (0x508280, 145 bytes)
```c
PhyrePClassDescriptor *__thiscall Phyre_PAnimationSlotArray_RegisterDescriptor(PhyrePClassDescriptor *this)
{
  DefaultPool = Phyre_GetDefaultPool();
  Singleton = Phyre_PNamespace_GetSingleton();
  Phyre_PClassDescriptor_ctor(this, Singleton, "PAnimationSlotListIndex", 16, 4, DefaultPool, 0);
  *((_DWORD *)this + 36) |= 2u;
  this->vfptr = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationSlotListIndex>::vftable;
  Phyre_PClassDescriptor_SetField64(this, &val__26);
  Phyre_PClassDescriptor_SetField68(this, &val__27);
  Phyre_PClassDescriptor_SetField6C(this, &val__28);
}
```
- **Class:** `PAnimationSlotListIndex` (size=16, align=4)
- **Vtable:** 0xB251A4

#### Phyre_PAnimationTarget_ClassDescriptorInit (0x5085d0, 376 bytes)
- **Callees:** Phyre_GetDefaultPool, GetSingleton, PClassDescriptor_ctor, SetField64/68/6C
- **Purpose:** Larger class descriptor initializer (likely PAnimationTarget itself)
- **Note:** Template-generated Init function, follows same pattern with more fields

---

### Destructor Variants

#### DtorWithVftable (11 bytes each)
Set vfptr then delegate to Phyre_PClassDescriptor_Destructor:

```c
bool __thiscall Phyre_PAnimationSlotArray_ClassDescriptor_DtorWithVftable(
    PhyrePClassDescriptor *this, bool flags)
{
  this->vfptr = &Phyre::PClassDescriptorForType<Phyre::PAnimation::PAnimationSlotArray>::vftable;
  return Phyre_PClassDescriptor_Destructor(this, flags);
}
```

| Function | Address | Size | Vtable |
|----------|---------|------|--------|
| PAnimationSlotArray_DtorWithVftable | 0x5083f0 | 11 | 0xB2524C |
| PAnimationSlotListIndex_DtorWithVftable | 0x508400 | 11 | 0xB2515C |
| PAnimationSlotArray_DtorWithVftable_A | 0x508410 | 11 | 0xB2524C |
| PAnimationSlotListIndex_DtorWithVftable_A | 0x508420 | 11 | 0xB2515C |

#### DtorWithFree (39 bytes each)
Set vfptr → Destructor → conditional Engine_AlignedFree:

```c
PhyrePClassDescriptor *__thiscall DtorWithFree(PhyrePClassDescriptor *this, char a2)
{
  this->vfptr = &vtable;
  Phyre_PClassDescriptor_Destructor(this, flags);
  if ( (a2 & 1) != 0 )
    Engine_AlignedFree(this);
  return this;
}
```

| Function | Address | Size | Vtable |
|----------|---------|------|--------|
| PAnimationSlotArray_PClassDescriptor_DtorWithFree | 0x508490 | 39 | — |
| PAnimationSlotListIndex_PClassDescriptor_DtorWithFree | 0x5084c0 | 39 | — |
| PAnimationSlotArray_PClassDescriptor_DtorWithFree_A | 0x5084f0 | 39 | — |
| PAnimationSlotListIndex_PClassDescriptor_DtorWithFree_A | 0x508520 | 39 | — |
| PAnimationSlotArray_PClassDescriptor_DtorWithFree_B | 0x508550 | 39 | — |
| PAnimationSlotListIndex_PClassDescriptor_DtorWithFree_B | 0x508580 | 39 | — |

**Observation:** 6 DtorWithFree variants for just 2 types — multiple vtable slots (DtorV0-V5).

---

### Simple Accessors

#### Phyre_PAnimationSlotArray_ReturnThis (0x5083c0, 3 bytes)
```c
void *__thiscall Phyre_PAnimationSlotArray_ReturnThis(void *this)
{
  return this;
}
```

#### Phyre_PAnimationSlotArray_GetIndex_Ret2 (0x508b30, 6 bytes)
```c
int Phyre_PAnimationSlotArray_GetIndex_Ret2()
{
  return 2;
}
```

#### Phyre_PAnimationSlotArray_SupportsType_RetTrue (0x508da0, 5 bytes)
```c
bool Phyre_PAnimationSlotArray_SupportsType_RetTrue()
{
  return true;
}
```

---

### Init Functions

#### Phyre_PAnimationSlotArray_InitStruct (0x5083d0, 30 bytes)
```c
_DWORD *__thiscall Phyre_PAnimationSlotArray_InitStruct(_DWORD *this)
{
  this[0] = 0;
  this[1] = 3;      // magic: 3 slots?
  this[2] = 0;
  this[3] = 0;
  return this;
}
```
- **Purpose:** Zero-init with slot count=3

---

### Sub-Register Functions

#### Phyre_PAnimationSlotListIndex_RegisterDescriptor_Sub (0x508750, 193 bytes)
- **Purpose:** Sub-registration for PAnimationSlotListIndex

#### Phyre_PAnimationChannelTarget_RegisterDescriptor_Sub (0x508820, 193 bytes)
- **Purpose:** Sub-registration for PAnimationChannelTarget

---

### Serialization

#### Phyre_PAnimationTarget_Serialize (0x508d00, 109 bytes)
- **Purpose:** Serialize PAnimationTarget to stream (size=4)

#### Phyre_PAnimationTarget_GetTargetCount (0x508db0, 43 bytes)
```c
int __thiscall Phyre_PAnimationTarget_GetTargetCount(void *this)
{
  // Returns count based on type lookup
}
```
- **Purpose:** Returns number of animation targets

---

## PAnimation Types Discovered

| Type | Size | Align | ClassName String | Vtable |
|------|------|-------|-----------------|--------|
| PAnimationSlotArray | 4 | 4 | "PAnimationSlotArray" | 0xB25294 |
| PAnimationSlotListIndex | 16 | 4 | "PAnimationSlotListIndex" | 0xB251A4 |

---

## Key Findings

1. **Standard class descriptor boilerplate** — RegisterDescriptor pattern identical to PClassDescriptor/PNamespace: GetDefaultPool → GetSingleton → PClassDescriptor_ctor → SetField64/68/6C

2. **6 destructor variants per type** — DtorWithVftable (2 types × 2 variants) + DtorWithFree (2 types × 3 variants) = 10 destructor thunks total in this batch. These are the DtorV0-DtorV5 vtable slots.

3. **PAnimationSlotArray size=4** — tiny struct (just vfptr + one field?)
4. **PAnimationSlotListIndex size=16** — larger (vfptr + 3 fields?)

5. **Slot count=3** — InitStruct sets field[1]=3, suggesting 3 animation slots per target

---

## Next Batches

- Batch 7 Part 2: Remaining PAnimation functions (635+ more)
- Batch 8: Phyre_PInput family (~632 functions)
- Batch 9+: PPhysics, PGeometry, PSceneNode
