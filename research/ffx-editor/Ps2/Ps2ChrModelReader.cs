using System;
using System.Buffers.Binary;
using System.IO;

namespace FFXProjectEditor.FfxLib.Ps2
{
    // FFX PS2 .chr Model Reader
    // Source: IDA RE via FFX_Chr_AllocAndLoadModelData@0x8263c0, sub_825F60, sub_827610, sub_827870.
    // See: docs/reverse/FFX_STRUCTURE_COMPLETE_2026-08-17.md sections 7.6 and 8.18.
    internal sealed class ChrBone
    {
        public ushort ParentIndex;
        public short RotX, RotY, RotZ;
        public short TransX, TransY, TransZ;
        public short ScaleX, ScaleY, ScaleZ;
        public float RotXRadians => (float)(RotX / 100.0 * Math.PI / 180.0);
        public float RotYRadians => (float)(RotY / 100.0 * Math.PI / 180.0);
        public float RotZRadians => (float)(RotZ / 100.0 * Math.PI / 180.0);
        public float TransXFloat => TransX / 1000f;
        public float TransYFloat => TransY / 1000f;
        public float TransZFloat => TransZ / 1000f;
        public float ScaleXFloat => ScaleX / 4096f;
        public float ScaleYFloat => ScaleY / 4096f;
        public float ScaleZFloat => ScaleZ / 4096f;
        public bool IsRoot => ParentIndex == _selfIndex;
        internal int _selfIndex;
    }
    internal sealed class ChrPtrEntry { public int Index; public uint Ptr; public uint Count; }
    internal sealed class ChrRemapTable { public ushort Key; public ushort Count; public ushort[] Entries = Array.Empty<ushort>(); }
    internal sealed class Ps2ChrModel
    {
        public byte[] RawData = Array.Empty<byte>();
        public uint SelfOffset, NumPtrFields, Version, Reserved;
        public ChrPtrEntry[] PtrTable = Array.Empty<ChrPtrEntry>();
        public int SkeletonFileOffset; public uint SkeletonBase;
        public ushort StrideSelector, NumObjects, BoneCount;
        public float InstScale; public int BoneArrayFileOffset, NodeCount;
        public ChrBone[] Bones = Array.Empty<ChrBone>();
        public int RemapFileOffset, RemapTableCount;
        public ChrRemapTable[] RemapTables = Array.Empty<ChrRemapTable>();
        public string Summary => $"CHR {RawData.Length} bytes, {BoneCount} bones";
        public char Category { get; set; }
        public string ModelId { get; set; } = "";
    }
    internal static class Ps2ChrModelReader
    {
        const int HeaderSize = 0x68; const int PtrStride = 8; const int BoneStride = 20; const int MaxPtrFields = 16;
        public static Ps2ChrModel? ReadFile(string path) { try { return ParseBytes(File.ReadAllBytes(path)); } catch { return null; } }
        public static Ps2ChrModel? ParseBytes(byte[] data)
        {
            if (data.Length < HeaderSize) return null;
            var model = new Ps2ChrModel { RawData = data };
            model.SelfOffset = U32(data, 0); model.NumPtrFields = U32(data, 4);
            model.Version = U32(data, 8); model.Reserved = U32(data, 0xC);
            if (model.SelfOffset != 0 || model.NumPtrFields == 0 || model.NumPtrFields > MaxPtrFields) return null;
            int nPtr = (int)model.NumPtrFields;
            model.PtrTable = new ChrPtrEntry[nPtr];
            for (int i = 0; i < nPtr; i++) { int off = 0x10 + i * PtrStride; model.PtrTable[i] = new ChrPtrEntry { Index = i, Ptr = U32(data, off), Count = U32(data, off + 4) }; }
            ParseSkeleton(model, data); ParseRemap(model, data); return model;
        }
        static void ParseSkeleton(Ps2ChrModel model, byte[] data)
        {
            if (model.PtrTable.Length < 1) return;
            uint skelPtr = model.PtrTable[0].Ptr;
            if (skelPtr == 0 || skelPtr + 68 > data.Length) return;
            int skel = (int)skelPtr; model.SkeletonFileOffset = skel; model.SkeletonBase = U32(data, skel);
            model.StrideSelector = U16(data, skel + 4); model.NumObjects = U16(data, skel + 6); model.BoneCount = U16(data, skel + 10);
            if (model.PtrTable.Length > 2) model.NodeCount = (int)model.PtrTable[2].Count;
            uint boneArrayStored = U32(data, skel + 28);
            int boneArrayFile = (int)(boneArrayStored + skel - model.SkeletonBase);
            model.BoneArrayFileOffset = boneArrayFile;
            if (model.PtrTable.Length > 9) { uint instStructPtr = model.PtrTable[9].Ptr; if (instStructPtr > 0 && instStructPtr + 36 <= data.Length) model.InstScale = BitConverter.ToSingle(data, (int)instStructPtr + 32) * 0.001f; }
            if (model.BoneCount > 0 && boneArrayFile > 0 && boneArrayFile + BoneStride * model.BoneCount <= data.Length)
            {
                model.Bones = new ChrBone[model.BoneCount];
                for (int i = 0; i < model.BoneCount; i++) { int b = boneArrayFile + BoneStride * i; model.Bones[i] = new ChrBone { _selfIndex = i, ParentIndex = U16(data, b), RotX = S16(data, b + 2), RotY = S16(data, b + 4), RotZ = S16(data, b + 6), TransX = S16(data, b + 8), TransY = S16(data, b + 10), TransZ = S16(data, b + 12), ScaleX = S16(data, b + 14), ScaleY = S16(data, b + 16), ScaleZ = S16(data, b + 18) }; }
            }
        }
        static void ParseRemap(Ps2ChrModel model, byte[] data)
        {
            if (model.PtrTable.Length < 5) return;
            uint remapPtr = model.PtrTable[4].Ptr; uint remapCount = model.PtrTable[4].Count;
            if (remapPtr == 0 || remapCount == 0) return;
            int remap = (int)remapPtr; model.RemapFileOffset = remap; model.RemapTableCount = (int)remapCount;
            if (remap + 4 * remapCount > data.Length) return;
            model.RemapTables = new ChrRemapTable[remapCount];
            for (int t = 0; t < remapCount; t++) { int tPtr = (int)U32(data, remap + 4 * t); var table = new ChrRemapTable(); if (tPtr > 0 && tPtr + 8 <= data.Length) { table.Key = U16(data, tPtr); table.Count = U16(data, tPtr + 2); if (table.Count > 0 && tPtr + 8 + 2 * table.Count <= data.Length) { table.Entries = new ushort[table.Count]; for (int j = 0; j < table.Count; j++) table.Entries[j] = U16(data, tPtr + 8 + 2 * j); } } model.RemapTables[t] = table; }
        }
        static ushort U16(byte[] d, int o) => BinaryPrimitives.ReadUInt16LittleEndian(d.AsSpan(o));
        static uint U32(byte[] d, int o) => BinaryPrimitives.ReadUInt32LittleEndian(d.AsSpan(o));
        static short S16(byte[] d, int o) => (short)BinaryPrimitives.ReadUInt16LittleEndian(d.AsSpan(o));
    }
}
