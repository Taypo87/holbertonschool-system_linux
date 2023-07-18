BITS 64

global asm_strlen

asm_strlen:

xor rax, rax
mov rcx, rdi

loop_start:

cmp byte [rcx], 0
je end
inc rcx
inc rax
jmp loop_start

end:
ret
