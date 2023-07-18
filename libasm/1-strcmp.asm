
global asm_strcmp

asm_strcmp:
xor rax, rax
mov rbx, rdi
mov rcx, rsi

loop_start:
mov al, [rbx]
mov dl, [rcx]
cmp al, 0x0
je first_null
cmp dl, 0x0
je sec_null
cmp al, dl
jl less_than
jg greater_than
inc rbx
inc rcx
jmp loop_start

first_null:
cmp al, dl
jne less_than
je end

sec_null:
cmp al, dl
jne greater_than
je end

less_than:
mov rax, -1
jmp end

greater_than:
mov rax, 1
jmp end

end:
ret