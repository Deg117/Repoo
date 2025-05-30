section.data
num db 2
num2 db 2
result db 0

section.tex
global_start

_start:
mov al, [num1]
add al, [num2]
add al,34
add al, 20
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



section.data
num db 2
num2 db 2
result db 0

section.tex
global_start

_start:
mov al, [num1]
add al, [num2]
add al,38
add al, 2
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

section.data
num db 2
num2 db 2
result db 0

section.tex
global_start

_start:
mov al, [num1]
add al, [num2]
add al,31
add al, 40
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



section.data
num db 2
num2 db 2
result db 0

section.tex
global_start

_start:
mov al, [num1]
add al, [num2]
add al,27
add al, 40
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


section.data
num db 2
num2 db 2
result db 0

section.tex
global_start

_start:
mov al, [num1]
add al, [num2]
add al,11
add al, 40
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