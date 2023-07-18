64 BIT

global _strlen

_strlen:

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
