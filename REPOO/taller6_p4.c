section.data
num db 2
num2 db 2
result db 0

section.tex
global_start

_start:
mov al, [num1]
add al, [num2]
add al, 43
add al, '0'

mov [result],al 

mov eax, 4 
mov ebx, 1 
mov ecx, result 
mov edx, 1 
int 0x80 

mov eax,1
xor ebx,ebx
int 0x80