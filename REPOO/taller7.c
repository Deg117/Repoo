section.data
msg_iguales db "los numeros son iguales "
msg_mayor db "el primer numero es mayor"
msg_menor db "el segundo numero es menor"
msg_negativo db "uno de los numeros es negativo"
section .bss
num1 resb 1
num2 resb 1

section .text 
global __start 
_start 

mov al, [num1]
cmp al, [num2]
je son_iguales
jg primer_mayor 
jl segundo_mayor

primer_mayor:
mov eax, msg_mayor
jmp imprimir

segundo_mayor:
mov eax, msg_menor
jmp imprimir

son_iguales:
mov eax, msg_iguales
jmp imprimir
