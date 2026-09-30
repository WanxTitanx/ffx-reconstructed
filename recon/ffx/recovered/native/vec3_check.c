/* Native x86 verifier only: this file is never an FFX C provider.
   Inline assembly observes the real calling convention and x87 state.
   The mapped game entry point is never executed. Only the recovered callee
   and its actual MSVCR110 _CIsqrt import are called. */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int U32;
typedef unsigned short U16;
typedef void (__cdecl *Normalize)(float *, const float *);
typedef struct Mapping { unsigned char *base; DWORD size; DWORD relocations; } Mapping;
typedef struct CallState { U16 status, control; int abi_ok; } CallState;

static const DWORD function_rva = 0x0053d3d0;
static const DWORD sqrt_iat_rva = 0x0070c3a0;
static const DWORD image_bytes = 37212160;

/* Reserve rebased test windows before CRT argument/locale initialization.
   Windows already maps loader data in the 0x400000 window before this entry;
   preferred-base mapping remains covered by the existing Linux i386 harness.
   These three Windows bases include both complete-acceptance rebasing bases. */
void __cdecl mainCRTStartup(void);
void __cdecl reserve_start(void) {
    static const DWORD bases[4] = {0x10000000, 0x20000000, 0x50000000, 0x60000000};
    static const char message[] = "FAIL reserving PE windows before CRT initialization\r\n";
    DWORD i, written;
    for (i=0; i<4; ++i) {
        if (VirtualAlloc((void *)bases[i], image_bytes, MEM_RESERVE, PAGE_NOACCESS) != (void *)bases[i]) {
            WriteFile(GetStdHandle(STD_ERROR_HANDLE), message, sizeof(message)-1, &written, NULL);
            ExitProcess(120+i);
        }
    }
    mainCRTStartup();
    ExitProcess(124);
}
static const U32 samples[16] = {
    0x00000000, 0x80000000, 0x3f800000, 0xbf800000,
    0x40400000, 0x40800000, 0x3f000000, 0xbf000000,
    0x00800000, 0x00000001, 0x007fffff, 0x7f7fffff,
    0x7f800000, 0xff800000, 0x7fc12345, 0x7f812345
};

static void fail(const char *message) {
    fprintf(stderr, "FAIL %s error=%lu\n", message, GetLastError());
    exit(1);
}

static unsigned char *file_bytes(const char *name, DWORD *size) {
    FILE *stream;
    unsigned char *data;
    long length;
    stream = fopen(name, "rb");
    if (!stream || fseek(stream, 0, SEEK_END)) fail("open image");
    length = ftell(stream);
    if (length != 10675712 || fseek(stream, 0, SEEK_SET)) fail("image size");
    data = (unsigned char *)malloc((size_t)length);
    if (!data || fread(data, 1, (size_t)length, stream) != (size_t)length) fail("read image");
    fclose(stream);
    *size = (DWORD)length;
    return data;
}

static int inside(DWORD at, DWORD size, DWORD limit) {
    return at <= limit && size <= limit-at;
}

static Mapping map_image(const unsigned char *file, DWORD length, DWORD base, HMODULE crt) {
    Mapping mapped;
    IMAGE_DOS_HEADER *dos;
    IMAGE_NT_HEADERS32 *nt;
    IMAGE_SECTION_HEADER *section;
    IMAGE_DATA_DIRECTORY directory;
    DWORD delta, cursor, end, i, found, old_protect;
    IMAGE_IMPORT_DESCRIPTOR *descriptor;
    FARPROC square_root;
    dos = (IMAGE_DOS_HEADER *)file;
    if (dos->e_magic != IMAGE_DOS_SIGNATURE || dos->e_lfanew < 0 ||
        !inside((DWORD)dos->e_lfanew, sizeof(*nt), length)) fail("DOS header");
    nt = (IMAGE_NT_HEADERS32 *)(file+dos->e_lfanew);
    if (nt->Signature != IMAGE_NT_SIGNATURE || nt->FileHeader.Machine != IMAGE_FILE_MACHINE_I386 ||
        nt->OptionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR32_MAGIC ||
        nt->OptionalHeader.ImageBase != 0x400000 || nt->FileHeader.NumberOfSections != 7)
        fail("PE header");
    mapped.size = nt->OptionalHeader.SizeOfImage;
    if (mapped.size != image_bytes) fail("mapped image extent");
    mapped.relocations = 0;
    mapped.base = (unsigned char *)VirtualAlloc((void *)base, mapped.size,
        MEM_COMMIT, PAGE_READWRITE);
    if (mapped.base != (unsigned char *)base) {
        MEMORY_BASIC_INFORMATION memory;
        DWORD at = base;
        fprintf(stderr, "FAIL requested image base unavailable base=%08lx size=%lu error=%lu\n",
                base, mapped.size, GetLastError());
        while (at < base+mapped.size && VirtualQuery((void *)at, &memory, sizeof(memory))) {
            fprintf(stderr, "region=%p allocation=%p bytes=%lu state=%lx type=%lx\n",
                    memory.BaseAddress, memory.AllocationBase, (DWORD)memory.RegionSize,
                    memory.State, memory.Type);
            if ((DWORD)memory.BaseAddress+memory.RegionSize <= at) break;
            at = (DWORD)memory.BaseAddress+memory.RegionSize;
        }
        exit(1);
    }
    if (!inside(0, nt->OptionalHeader.SizeOfHeaders, length)) fail("header extent");
    memcpy(mapped.base, file, nt->OptionalHeader.SizeOfHeaders);
    section = IMAGE_FIRST_SECTION(nt);
    for (i=0; i<nt->FileHeader.NumberOfSections; ++i) {
        if (!inside(section[i].PointerToRawData, section[i].SizeOfRawData, length) ||
            !inside(section[i].VirtualAddress, section[i].SizeOfRawData, mapped.size)) fail("section extent");
        memcpy(mapped.base+section[i].VirtualAddress, file+section[i].PointerToRawData, section[i].SizeOfRawData);
    }
    delta = base-nt->OptionalHeader.ImageBase;
    directory = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC];
    if (!inside(directory.VirtualAddress, directory.Size, mapped.size)) fail("relocation directory");
    cursor = directory.VirtualAddress;
    end = cursor+directory.Size;
    while (cursor < end) {
        IMAGE_BASE_RELOCATION *block;
        U16 *records;
        DWORD count;
        if (!inside(cursor, sizeof(*block), end)) fail("relocation block");
        block = (IMAGE_BASE_RELOCATION *)(mapped.base+cursor);
        if (block->SizeOfBlock < sizeof(*block) || (block->SizeOfBlock&1) ||
            !inside(cursor, block->SizeOfBlock, end)) fail("relocation block size");
        records = (U16 *)(block+1);
        count = (block->SizeOfBlock-sizeof(*block))/2;
        for (i=0; i<count; ++i) {
            DWORD type, at;
            type = records[i]>>12;
            if (type == IMAGE_REL_BASED_ABSOLUTE) continue;
            if (type != IMAGE_REL_BASED_HIGHLOW) fail("unsupported base relocation");
            at = block->VirtualAddress+(records[i]&4095);
            if (!inside(at, 4, mapped.size)) fail("relocation site");
            *(DWORD *)(mapped.base+at) += delta;
            ++mapped.relocations;
        }
        cursor += block->SizeOfBlock;
    }
    if (mapped.relocations != 283602) fail("incomplete relocation coverage");
    directory = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    if (!inside(directory.VirtualAddress, directory.Size, mapped.size)) fail("import directory");
    descriptor = (IMAGE_IMPORT_DESCRIPTOR *)(mapped.base+directory.VirtualAddress);
    square_root = GetProcAddress(crt, "_CIsqrt");
    if (!square_root) fail("real MSVCR110 _CIsqrt export missing");
    found = 0;
    for (; descriptor->Name; ++descriptor) {
        DWORD *lookup;
        const char *dll;
        if (!inside((DWORD)((unsigned char *)descriptor-mapped.base), sizeof(*descriptor), mapped.size) ||
            !inside(descriptor->Name, 16, mapped.size)) fail("import descriptor");
        dll = (const char *)(mapped.base+descriptor->Name);
        if (_stricmp(dll, "MSVCR110.dll")) continue;
        lookup = (DWORD *)(mapped.base+descriptor->OriginalFirstThunk);
        for (i=0; lookup[i]; ++i) {
            IMAGE_IMPORT_BY_NAME *name;
            if (lookup[i]&IMAGE_ORDINAL_FLAG32) continue;
            if (!inside(lookup[i], 12, mapped.size)) fail("import lookup");
            name = (IMAGE_IMPORT_BY_NAME *)(mapped.base+lookup[i]);
            if (strcmp((const char *)name->Name, "_CIsqrt")) continue;
            if (descriptor->FirstThunk+4*i != sqrt_iat_rva) fail("unexpected sqrt import slot");
            *(FARPROC *)(mapped.base+sqrt_iat_rva) = square_root;
            ++found;
        }
    }
    if (found != 1 || mapped.base[0x5497b8] != 0xff || mapped.base[0x5497b9] != 0x25 ||
        *(DWORD *)(mapped.base+0x5497ba) != base+sqrt_iat_rva) fail("sqrt thunk binding");
    if (!VirtualProtect(mapped.base, mapped.size, PAGE_EXECUTE_READ, &old_protect)) fail("image protection");
    if (!FlushInstructionCache(GetCurrentProcess(), mapped.base, mapped.size)) fail("instruction cache");
    return mapped;
}

/* This wrapper is test instrumentation, not a recovered source implementation. */
static __declspec(noinline) CallState call_checked(Normalize function, float *destination,
                                                   const float *source, U16 control) {
    CallState result;
    U32 before_sp, after_sp, before_bp, after_bp, got_bx, got_si, got_di;
    U16 status, after_control;
    __asm {
        fninit
        fldcw control
        mov before_sp, esp
        mov before_bp, ebp
        mov ebx, 11223344h
        mov esi, 55667788h
        mov edi, 13579bdfh
        push source
        push destination
        mov eax, function
        call eax
        add esp, 8
        mov after_sp, esp
        mov after_bp, ebp
        mov got_bx, ebx
        mov got_si, esi
        mov got_di, edi
        fnstsw status
        fnstcw after_control
        fninit
    }
    result.status = status;
    result.control = after_control;
    result.abi_ok = before_sp == after_sp && before_bp == after_bp &&
        got_bx == 0x11223344 && got_si == 0x55667788 && got_di == 0x13579bdf &&
        after_control == control && !(status&0x3800);
    return result;
}

static void __cdecl deliberately_wrong(float *destination, const float *source) {
    destination[0] = source[0]*2.0f;
}

static U32 random_word(U32 *state) {
    U32 value = *state;
    value ^= value<<13;
    value ^= value>>17;
    value ^= value<<5;
    return *state = value;
}

static void verify_known(Normalize function) {
    U32 source[4] = {0x40400000, 0x40800000, 0, 0x42280000};
    U32 dest[4] = {1, 2, 3, 4};
    U32 expected[4] = {0x3f19999a, 0x3f4ccccd, 0, 0x42280000};
    CallState result = call_checked(function, (float *)dest, (float *)source, 0x037f);
    if (!result.abi_ok || memcmp(dest, expected, 16)) fail("known 3-4-0 normalization");
    memset(source, 0, sizeof(source));
    result = call_checked(function, (float *)dest, (float *)source, 0x037f);
    if (!result.abi_ok || memcmp(dest, expected, 16)) fail("zero length must not write");
    source[0] = 0x7fc12345;
    result = call_checked(function, (float *)dest, (float *)source, 0x037f);
    if (!result.abi_ok || memcmp(dest, expected, 16)) fail("unordered length must not write");
}

static DWORD exercise(Normalize reference, Normalize candidate, DWORD base) {
    DWORD index, mode, alias, cases = 0;
    for (index=0; index<4608; ++index) {
        U32 words[4], state;
        DWORD part;
        if (index<4096) {
            words[0] = samples[index&15];
            words[1] = samples[(index>>4)&15];
            words[2] = samples[(index>>8)&15];
            words[3] = samples[(index^(index>>4))&15];
        } else {
            state = 0x12345678u+index;
            for (part=0; part<4; ++part) words[part] = random_word(&state);
        }
        for (mode=0; mode<12; ++mode) for (alias=0; alias<2; ++alias) {
            U32 source_a[20], source_b[20], dest_a[20], dest_b[20];
            U32 initial_source[20], initial_dest[20];
            DWORD offset = 4+(index&3);
            DWORD precision[3] = {0, 0x200, 0x300};
            U16 control = (U16)(0x7f | precision[mode/4] | ((mode%4)<<10));
            CallState a, b;
            memset(source_a, 0xa5, sizeof(source_a));
            memset(dest_a, 0xcd, sizeof(dest_a));
            memcpy(source_a+offset, words, 16);
            memcpy(source_b, source_a, sizeof(source_a));
            memcpy(dest_b, dest_a, sizeof(dest_a));
            memcpy(initial_source, source_a, sizeof(source_a));
            memcpy(initial_dest, dest_a, sizeof(dest_a));
            a = call_checked(reference, (float *)((alias ? source_a : dest_a)+offset),
                             (const float *)(source_a+offset), control);
            b = call_checked(candidate, (float *)((alias ? source_b : dest_b)+offset),
                             (const float *)(source_b+offset), control);
            if (!a.abi_ok || !b.abi_ok || a.control != b.control || ((a.status^b.status)&0x3f) ||
                memcmp(source_a, source_b, sizeof(source_a)) || memcmp(dest_a, dest_b, sizeof(dest_a))) {
                fprintf(stderr, "FAIL vec3 base=%08lx index=%lu mode=%lu alias=%lu abi=%d/%d status=%x/%x\n",
                        base, index, mode, alias, a.abi_ok, b.abi_ok, a.status, b.status);
                exit(1);
            }
            for (part=0; part<20; ++part) {
                if ((!alias || part<offset || part>=offset+4) && source_a[part] != initial_source[part]) fail("source/sentinel write");
                if ((alias || part<offset || part>=offset+4) && dest_a[part] != initial_dest[part]) fail("destination sentinel write");
            }
            ++cases;
        }
    }
    return cases;
}

int main(int argc, char **argv) {
    unsigned char *original, *candidate;
    DWORD original_size, candidate_size, index, cases;
    DWORD bases[3] = {0x10000000, 0x20000000, 0x50000000};
    HMODULE crt;
    Mapping reference;
    int negative;
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);
    if (argc != 4 && argc != 5) fail("expected reference candidate runtime [negative]");
    negative = argc == 5;
    original = file_bytes(argv[1], &original_size);
    candidate = file_bytes(argv[2], &candidate_size);
    if (original_size != candidate_size || memcmp(original, candidate, original_size)) fail("whole files differ");
    crt = LoadLibraryA(argv[3]);
    if (!crt) fail("load original game CRT");
    reference = map_image(original, original_size, 0x60000000, crt);
    verify_known((Normalize)(reference.base+function_rva));
    for (index=0; index<3; ++index) {
        Mapping mapped = map_image(candidate, candidate_size, bases[index], crt);
        Normalize function = negative ? deliberately_wrong : (Normalize)(mapped.base+function_rva);
        if (!negative) verify_known(function);
        cases = exercise((Normalize)(reference.base+function_rva), function, bases[index]);
        printf("PASS vec3 base=%08lx cases=%lu calls=%lu modes=12 alias_modes=2 relocations=%lu\n",
               bases[index], cases, cases*2, mapped.relocations);
        if (!VirtualFree(mapped.base, 0, MEM_RELEASE)) fail("unmap candidate");
    }
    VirtualFree(reference.base, 0, MEM_RELEASE);
    FreeLibrary(crt);
    free(original);
    free(candidate);
    return 0;
}
