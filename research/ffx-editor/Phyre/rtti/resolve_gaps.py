#!/usr/bin/env python3
"""Gap resolution: search IDA function names for each gap's alternative names."""
import idautils, idc

GAPS = {
    "PhyrePClassDescriptor": ["ClassDescriptor_Register", "PClassDescriptor_"],
    "PhyrePNamespace": ["PNamespace_", "Namespace_Register"],
    "PhyrePApplication": ["Application_Register", "PApplication_"],
    "PhyrePRendererBase": ["RendererBase", "PRenderer_"],
    "PhyrePArray": ["PArray_", "Array_Register"],
    "PhyrePString": ["PString_", "String_Register", "StringNode"],
    "PhyrePResult": ["PResult_"],
    "PhyrePThreadPool": ["ThreadPool", "PThreadPool"],
    "PhyrePJobQueue": ["JobQueue", "PJobQueue"],
    "PhyrePTimer": ["PTimer", "Timer_Register"],
    "PhyrePInputDevice": ["InputDevice", "PInput"],
    "PhyrePGeometry": ["Geometry_Register", "PGeometry_"],
    "PhyrePVector2": ["Vector2", "PVector2", "Vec2"],
    "PhyrePVector3": ["Vector3", "PVector3", "Vec3"],
    "PhyrePVector4": ["Vector4", "PVector4", "Vec4"],
    "PhyrePColor": ["PColor", "Color_Register"],
    "PhyrePList": ["PList", "List_Register"],
    "PhyrePTreeNode": ["TreeNode", "PTreeNode"],
    "PhyrePCluster": ["PCluster", "Cluster_"],
    "PhyrePRefCountObject": ["RefCount", "PRefCount"],
    "PhyrePAllocator": ["Allocator", "PAllocator"],
    "PhyrePArrayPObject": ["PObject", "PArrayPObject"],
    "PhyrePInstancesComponent": ["Instances", "PInstancesComponent"],
    "PhyreStringNode": ["StringNode", "PStringNode"],
    "PhyreZlibState": ["Zlib", "zlib"],
    "PhyreClassDescriptorEntry": ["DescriptorEntry", "ClassDescriptorEntry"],
}

names = []
for f in idautils.Functions():
    n = idc.get_func_name(f)
    if n:
        names.append((f, n))

out = []
for gap, pats in GAPS.items():
    hits = []
    for ea, n in names:
        for p in pats:
            if p.lower() in n.lower():
                hits.append((ea, n))
                break
    out.append(f"### {gap}")
    if not hits:
        out.append("  (sem hits)")
    else:
        for ea, n in hits[:12]:
            out.append(f"  0x{ea:x} {n}")

with open(r"C:\Users\wande\Documents\ffx-editor-main\work\phyre_rtti\gap_lookup.txt", "w", encoding="utf-8") as f:
    f.write("\n".join(out))
print("saved", len(out), "lines")
