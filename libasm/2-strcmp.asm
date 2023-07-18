BITS 64

section .text
global asm_strncmp

asm_strncmp:
    mov rdi, rdi
    mov rsi, rsi
    mov rcx, rdx

.loop:
    cmp rcx, 0
    je .end

    mov al, [rdi]
    cmp al, [rsi]
    jne .unequal

    cmp al, 0
    je .end

    inc rdi
    inc rsi
    dec rcx 
    jmp .loop 

.end:
    mov eax, 0
    ret

.unequal:
    mov eax, 1
    ret
