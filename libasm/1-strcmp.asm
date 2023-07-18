BITS 64

section .text
global asm_strcmp

asm_strcmp:
    mov rsi, rdi
    mov rdx, r8

    cmp rdi, rsi
    je .end

.loop:
    mov al, [rdi]
    cmp al, [rsi]
    jne .unequal

    cmp al, 0
    je .end

    inc rdi
    inc rsi
    dec rdx
    jnz .loop

.end:
    mov eax, 0
    ret

.unequal:
    mov eax, 1
    ret
