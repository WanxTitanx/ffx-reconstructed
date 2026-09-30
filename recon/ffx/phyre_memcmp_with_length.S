/* x86 cdecl reconstruction of FFX.exe VA 0x617420.
 * Record: unsigned key, unsigned length, const unsigned char *data.
 * Keys/lengths sort left/right; equal records compare right/left data.
 * Instruction reconstruction; not a recovered C compiler input.
 */
.intel_syntax noprefix
.code32
.text
.globl Phyre_MemCmp_WithLength
.type Phyre_MemCmp_WithLength, @function
Phyre_MemCmp_WithLength:
    push ebp
    {load} mov ebp, esp
    mov edx, DWORD PTR [ebp+12]
    push esi
    mov esi, DWORD PTR [ebp+8]
    mov ecx, DWORD PTR [edx]
    mov eax, DWORD PTR [esi]
    {load} cmp eax, ecx
    ja .Lgreater
    jb .Lless
    mov ecx, DWORD PTR [esi+4]
    mov eax, DWORD PTR [edx+4]
    {load} cmp ecx, eax
    jbe .Llength_not_greater
.Lgreater:
    mov eax, 1
    pop esi
    pop ebp
    ret
.Llength_not_greater:
    jae .Lcompare_data
.Lless:
    or eax, -1
    pop esi
    pop ebp
    ret
.Lcompare_data:
    mov edx, DWORD PTR [edx+8]
    mov esi, DWORD PTR [esi+8]
    sub ecx, 4
    jb .Ltail
    {disp32} lea esp, [esp]
.Lwords:
    mov eax, DWORD PTR [edx]
    cmp eax, DWORD PTR [esi]
    jne .Lbytes
    add edx, 4
    add esi, 4
    sub ecx, 4
    jae .Lwords
.Ltail:
    cmp ecx, -4
    je .Lequal
.Lbytes:
    mov al, BYTE PTR [edx]
    cmp al, BYTE PTR [esi]
    jne .Lsign
    cmp ecx, -3
    je .Lequal
    mov al, BYTE PTR [edx+1]
    cmp al, BYTE PTR [esi+1]
    jne .Lsign
    cmp ecx, -2
    je .Lequal
    mov al, BYTE PTR [edx+2]
    cmp al, BYTE PTR [esi+2]
    jne .Lsign
    cmp ecx, -1
    je .Lequal
    mov al, BYTE PTR [edx+3]
    cmp al, BYTE PTR [esi+3]
    je .Lequal
.Lsign:
    {load} sbb eax, eax
    or eax, 1
    pop esi
    pop ebp
    ret
.Lequal:
    {load} xor eax, eax
    pop esi
    pop ebp
    ret
.size Phyre_MemCmp_WithLength, .-Phyre_MemCmp_WithLength
.section .note.GNU-stack,"",@progbits
