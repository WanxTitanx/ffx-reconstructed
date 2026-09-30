.section .text
.global _start
.type _start,@function
_start:
    and $-16, %esp
    call harness_main
    mov %eax, %ebx
    mov $1, %eax
    int $0x80

.global sys_open
.type sys_open,@function
sys_open:
    push %ebx
    mov 8(%esp), %ebx
    mov 12(%esp), %ecx
    mov 16(%esp), %edx
    mov $5, %eax
    int $0x80
    pop %ebx
    ret

.section .note.GNU-stack,"",@progbits
.section .text

.global sys_lseek
.type sys_lseek,@function
sys_lseek:
    push %ebx
    mov 8(%esp), %ebx
    mov 12(%esp), %ecx
    mov 16(%esp), %edx
    mov $19, %eax
    int $0x80
    pop %ebx
    ret

.global sys_write
.type sys_write,@function
sys_write:
    push %ebx
    mov 8(%esp), %ebx
    mov 12(%esp), %ecx
    mov 16(%esp), %edx
    mov $4, %eax
    int $0x80
    pop %ebx
    ret

.global sys_close
.type sys_close,@function
sys_close:
    push %ebx
    mov 8(%esp), %ebx
    mov $6, %eax
    int $0x80
    pop %ebx
    ret

.global sys_mmap2
.type sys_mmap2,@function
sys_mmap2:
    push %ebp
    push %ebx
    push %esi
    push %edi
    mov 20(%esp), %ebx
    mov 24(%esp), %ecx
    mov 28(%esp), %edx
    mov 32(%esp), %esi
    mov 36(%esp), %edi
    mov 40(%esp), %ebp
    mov $192, %eax
    int $0x80
    pop %edi
    pop %esi
    pop %ebx
    pop %ebp
    ret

.global sys_mprotect
.type sys_mprotect,@function
sys_mprotect:
    push %ebx
    mov 8(%esp), %ebx
    mov 12(%esp), %ecx
    mov 16(%esp), %edx
    mov $125, %eax
    int $0x80
    pop %ebx
    ret
