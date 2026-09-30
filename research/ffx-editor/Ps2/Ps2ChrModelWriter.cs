using System;
using System.Buffers.Binary;
using System.IO;

namespace FFXProjectEditor.FfxLib.Ps2
{
    // FFX PS2 .chr Model Writer
    // Re-emits a .chr file preserving byte-identical output when no edits are made (RT0).
    internal static class Ps2ChrModelWriter
    {
        const int BoneStride = 20;
        public static void Write(Ps2ChrModel model, Stream stream)
        {
            byte[] output = (byte[])model.RawData.Clone();
            if (model.Bones != null && model.BoneArrayFileOffset > 0 && model.BoneCount > 0)
            {
                for (int i = 0; i < model.BoneCount && i < model.Bones.Length; i++)
                {
                    int b = model.BoneArrayFileOffset + BoneStride * i;
                    var bone = model.Bones[i];
                    WriteU16(output, b, bone.ParentIndex);
                    WriteS16(output, b + 2, bone.RotX); WriteS16(output, b + 4, bone.RotY); WriteS16(output, b + 6, bone.RotZ);
                    WriteS16(output, b + 8, bone.TransX); WriteS16(output, b + 10, bone.TransY); WriteS16(output, b + 12, bone.TransZ);
                    WriteS16(output, b + 14, bone.ScaleX); WriteS16(output, b + 16, bone.ScaleY); WriteS16(output, b + 18, bone.ScaleZ);
                }
            }
            stream.Write(output, 0, output.Length);
        }
        public static void WriteToFile(Ps2ChrModel model, string path) { using var fs = new FileStream(path, FileMode.Create, FileAccess.Write, FileShare.None); Write(model, fs); }
        public static byte[] RoundTrip(byte[] input) { var model = Ps2ChrModelReader.ParseBytes(input); if (model == null) throw new InvalidDataException("Failed to parse .chr model"); using var ms = new MemoryStream(input.Length); Write(model, ms); return ms.ToArray(); }
        static void WriteU16(byte[] d, int o, ushort v) => BinaryPrimitives.WriteUInt16LittleEndian(d.AsSpan(o), v);
        static void WriteS16(byte[] d, int o, short v) => BinaryPrimitives.WriteUInt16LittleEndian(d.AsSpan(o), (ushort)v);
    }
}
