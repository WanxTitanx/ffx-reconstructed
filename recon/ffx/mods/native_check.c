typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern int sys_open(const char *, int, int);
extern int sys_lseek(int, int, int);
extern int sys_write(int, const void *, unsigned);
extern int sys_close(int);
extern void *sys_mmap2(void *, unsigned, int, int, int, unsigned);
extern int sys_mprotect(void *, unsigned, int);

#define PROT_READ 1
#define PROT_WRITE 2
#define PROT_EXEC 4
#define MAP_PRIVATE 2
#define MAP_FIXED 0x10
#define MAP_ANONYMOUS 0x20
#define SEEK_END 2
#include "native_config.h"
static const char expected_description[] =
    "Source-built comparison demo: static calls, added code and data, no runtime installer.";

static u16 rd16(const u8 *p)
{
    return (u16)((u16)p[0] | ((u16)p[1] << 8));
}

static u32 rd32(const u8 *p)
{
    return (u32)p[0] | ((u32)p[1] << 8) | ((u32)p[2] << 16) | ((u32)p[3] << 24);
}

static void wr32(u8 *p, u32 value)
{
    p[0] = (u8)value;
    p[1] = (u8)(value >> 8);
    p[2] = (u8)(value >> 16);
    p[3] = (u8)(value >> 24);
}

static void copy_bytes(u8 *to, const u8 *from, u32 size)
{
    while (size--)
        *to++ = *from++;
}

static u32 string_length(const char *s)
{
    u32 n = 0;
    while (s[n])
        ++n;
    return n;
}

static int string_equal(const char *a, const char *b)
{
    while (*a && *a == *b) {
        ++a;
        ++b;
    }
    return *a == *b;
}

static void write_text(const char *s)
{
    u32 left = string_length(s);
    while (left) {
        int done = sys_write(1, s, left);
        if (done <= 0)
            return;
        s += done;
        left -= (u32)done;
    }
}

static void write_hex(u32 value)
{
    static const char digits[] = "0123456789abcdef";
    char out[11];
    int i;
    out[0] = '0';
    out[1] = 'x';
    for (i = 0; i < 8; ++i)
        out[2 + i] = digits[(value >> (28 - i * 4)) & 15];
    out[10] = 0;
    write_text(out);
}

static void write_dec(u32 value)
{
    char out[11];
    int at = 10;
    out[10] = 0;
    do {
        out[--at] = (char)('0' + value % 10);
        value /= 10;
    } while (value);
    write_text(out + at);
}

static int fail(const char *reason, int code)
{
    write_text("FAIL native candidate harness: " );
    write_text(reason);
    write_text("\n");
    return code;
}

static int bad_pointer(const void *p)
{
    return (u32)p >= 0xfffff001u;
}

static int section_name(const u8 *section, const char *name)
{
    int i;
    for (i = 0; i < 8; ++i) {
        char expected = name[i];
        if (section[i] != (u8)expected)
            return 0;
        if (!expected)
            return 1;
    }
    return 1;
}

struct ComparisonRecord {
    u32 sequence;
    u32 length;
    s32 ordering;
    s32 returned_value;
};

typedef int (__attribute__((cdecl)) *comparison_fn)(const void *, const void *, u32);

static comparison_fn compare_fn;
static volatile u32 *compare_calls;
static volatile s32 *compare_scale;
static volatile struct ComparisonRecord *compare_records;
static u32 expected_sequence;

static int run_case(const u8 *left, const u8 *right, u32 length, s32 ordering)
{
    s32 scale = *compare_scale;
    s32 expected = ordering * scale;
    int actual = compare_fn(left, right, length);
    volatile struct ComparisonRecord *record;
    ++expected_sequence;
    if (actual != expected)
        return 1;
    if (*compare_calls != expected_sequence)
        return 2;
    record = &compare_records[expected_sequence & 7u];
    if (record->sequence != expected_sequence || record->length != length
            || record->ordering != ordering || record->returned_value != expected)
        return 3;
    return 0;
}

int harness_main(void)
{
    int fd = sys_open(candidate_path, 0, 0);
    int file_size;
    u8 *file;
    u8 *image;
    u32 pe_offset, optional_offset, section_table, image_size, header_size;
    u32 preferred, delta, reloc_rva, reloc_size, cursor, relocation_count = 0;
    u16 section_count, optional_size;
    u32 i, alignment;
    int have_text = 0, have_ro = 0, have_data = 0;
    u8 left_storage[68], right_storage[68];
    u8 *left, *right;
    static const s32 scales[2] = {7, 11};

    if (fd < 0)
        return fail("open candidate", 10);
    file_size = sys_lseek(fd, 0, SEEK_END);
    if (file_size < 1024)
        return fail("candidate size", 11);
    file = (u8 *)sys_mmap2(0, (u32)file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    sys_close(fd);
    if (bad_pointer(file))
        return fail("map candidate file", 12);
    if (rd16(file) != 0x5a4d)
        return fail("DOS signature", 13);
    pe_offset = rd32(file + 0x3c);
    if (pe_offset > (u32)file_size - 24 || rd32(file + pe_offset) != 0x00004550u)
        return fail("PE signature", 14);
    if (rd16(file + pe_offset + 4) != 0x014c)
        return fail("machine is not i386", 15);
    section_count = rd16(file + pe_offset + 6);
    optional_size = rd16(file + pe_offset + 20);
    optional_offset = pe_offset + 24;
    if (optional_offset + optional_size > (u32)file_size || optional_size < 144
            || rd16(file + optional_offset) != 0x010b)
        return fail("PE32 optional header", 16);
    preferred = rd32(file + optional_offset + 28);
    image_size = rd32(file + optional_offset + 56);
    header_size = rd32(file + optional_offset + 60);
    if (preferred != IMAGE_BASE || image_size <= RECORDS_RVA + 8u * 16u
            || header_size > image_size || header_size > (u32)file_size
            || rd32(file + optional_offset + 92) < 6)
        return fail("image layout", 17);
    section_table = optional_offset + optional_size;
    if (section_table + (u32)section_count * 40u > (u32)file_size)
        return fail("section table", 18);

    image = (u8 *)sys_mmap2((void *)LOAD_BASE, image_size,
                            PROT_READ | PROT_WRITE | PROT_EXEC,
                            MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);
    if (image != (u8 *)LOAD_BASE)
        return fail("map relocated image", 19);
    copy_bytes(image, file, header_size);

    for (i = 0; i < section_count; ++i) {
        const u8 *section = file + section_table + i * 40u;
        u32 virtual_size = rd32(section + 8);
        u32 rva = rd32(section + 12);
        u32 raw_size = rd32(section + 16);
        u32 raw_offset = rd32(section + 20);
        u32 extent = virtual_size > raw_size ? virtual_size : raw_size;
        u32 characteristics = rd32(section + 36);
        if (rva > image_size || extent > image_size - rva)
            return fail("section virtual range", 20);
        if (raw_size) {
            if (raw_offset > (u32)file_size || raw_size > (u32)file_size - raw_offset)
                return fail("section raw range", 21);
            copy_bytes(image + rva, file + raw_offset, raw_size);
        }
        if (section_name(section, ".modtxt")) {
            have_text = rva == FN_RVA && characteristics == 0x60000020u;
        } else if (section_name(section, ".modro")) {
            have_ro = rva == DESC_RVA && characteristics == 0x40000040u;
        } else if (section_name(section, ".moddat")) {
            have_data = rva == SCALE_RVA && characteristics == 0xc0000040u;
        }
    }
    if (!have_text || !have_ro || !have_data)
        return fail("mod section placement or permissions", 22);

    reloc_rva = rd32(file + optional_offset + 96 + 5 * 8);
    reloc_size = rd32(file + optional_offset + 96 + 5 * 8 + 4);
    if (!reloc_rva || !reloc_size || reloc_rva > image_size || reloc_size > image_size - reloc_rva)
        return fail("base relocation directory", 23);
    delta = LOAD_BASE - preferred;
    cursor = 0;
    while (cursor < reloc_size) {
        const u8 *block = image + reloc_rva + cursor;
        u32 page = rd32(block);
        u32 block_size = rd32(block + 4);
        u32 count, item;
        if (block_size < 8 || (block_size & 1) || block_size > reloc_size - cursor)
            return fail("relocation block", 24);
        count = (block_size - 8) / 2;
        for (item = 0; item < count; ++item) {
            u16 entry = rd16(block + 8 + item * 2);
            u32 type = entry >> 12;
            u32 patch_rva;
            if (!type)
                continue;
            if (type != 3)
                return fail("unsupported relocation type", 25);
            patch_rva = page + (entry & 0x0fffu);
            if (patch_rva > image_size - 4)
                return fail("relocation target", 26);
            wr32(image + patch_rva, rd32(image + patch_rva) + delta);
            ++relocation_count;
        }
        cursor += block_size;
    }
    if (cursor != reloc_size || relocation_count != EXPECTED_RELOCATIONS)
        return fail("relocation closure", 27);

    if (sys_mprotect(image, (header_size + 0xfffu) & ~0xfffu, PROT_READ))
        return fail("protect headers", 28);
    for (i = 0; i < section_count; ++i) {
        const u8 *section = file + section_table + i * 40u;
        u32 virtual_size = rd32(section + 8);
        u32 rva = rd32(section + 12);
        u32 raw_size = rd32(section + 16);
        u32 extent = virtual_size > raw_size ? virtual_size : raw_size;
        u32 characteristics = rd32(section + 36);
        u32 protection = 0;
        if (!extent)
            continue;
        if (characteristics & 0x40000000u) protection |= PROT_READ;
        if (characteristics & 0x80000000u) protection |= PROT_WRITE;
        if (characteristics & 0x20000000u) protection |= PROT_EXEC;
        if (!protection) protection = PROT_READ;
        extent = (extent + 0xfffu) & ~0xfffu;
        if (sys_mprotect(image + rva, extent, (int)protection))
            return fail("protect section", 29);
    }

    if (CALL_SITE_RVA > image_size - 5 || image[CALL_SITE_RVA] != 0xe8
            || CALL_SITE_RVA + 5u + rd32(image + CALL_SITE_RVA + 1) != FN_RVA)
        return fail("statically linked call does not reach replacement", 36);
    compare_fn = (comparison_fn)(image + CALL_SITE_RVA + 5u
                                + (s32)rd32(image + CALL_SITE_RVA + 1));
    compare_scale = (volatile s32 *)(image + SCALE_RVA);
    compare_calls = (volatile u32 *)(image + CALLS_RVA);
    compare_records = (volatile struct ComparisonRecord *)(image + RECORDS_RVA);
    if (*compare_scale != 7 || *compare_calls != 0
            || !string_equal((const char *)(image + DESC_RVA), expected_description))
        return fail("initial module data", 30);
    for (i = 0; i < 8u * 4u; ++i)
        if (((volatile u32 *)compare_records)[i] != 0)
            return fail("initial comparison records", 31);

    expected_sequence = 0;
    for (alignment = 0; alignment < 4; ++alignment) {
    left = left_storage + alignment;
    right = right_storage + (3u - alignment);
    for (i = 0; i < 64; ++i)
        left[i] = right[i] = (u8)(0x40u + (i & 0x1fu));
    for (i = 0; i < 2; ++i) {
        u32 length, position;
        *compare_scale = scales[i];
        for (length = 0; length <= 64; ++length) {
            if (run_case(length ? left : 0, length ? right : 0, length, 0))
                return fail("equal comparison behavior", 32);
        }
        for (length = 1; length <= 64; ++length) {
            for (position = 0; position < length; ++position) {
                right[position] = (u8)(left[position] + 1);
                if (run_case(left, right, length, -1))
                    return fail("less-than comparison behavior", 33);
                right[position] = (u8)(left[position] - 1);
                if (run_case(left, right, length, 1))
                    return fail("greater-than comparison behavior", 34);
                right[position] = left[position];
            }
        }
    }
    }
    if (expected_sequence != 33800 || *compare_calls != 33800 || *compare_scale != 11)
        return fail("final module state", 35);

    write_text("PASS native candidate harness\nloaded=");
    write_hex(LOAD_BASE);
    write_text(" preferred=");
    write_hex(preferred);
    write_text(" delta=");
    write_hex(delta);
    write_text(" relocations=");
    write_dec(relocation_count);
    write_text(" cases=");
    write_dec(expected_sequence);
    write_text(" calls=");
    write_dec(*compare_calls);
    write_text(" final_scale=");
    write_dec((u32)*compare_scale);
    write_text("\n");
    return 0;
}
