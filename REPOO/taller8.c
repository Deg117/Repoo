section .data
num1 db 5 ; Declaracion de la variable num1 con valor 5
num2 db 11 ; Declaracion de la variable num2 con valor 11
result db 0 ; Espacio reservado para almacenar el resultado
msg db 'Resultado: ', 0 ; Cadena de texto para mostrar el mensaje
section .bss
buffer resb 4 ; Reserva 4 bytes para el buffer de impresión
section .text
global _start
_start:
mov al, [num1] ; Carga el valor de num1 (5) al registro AL
add al, [num2] ; Suma el valor de num2 (11) al registro AL
mov [result], al ; Guarda el resultado de la suma en result
Convertir el numero a ASCII para impresion
movzx eax, byte [result] ; Extension con cero del byte result a eax
add eax, 48 ; Sumar 48 para convertir el numero a su caracter ASCII
mov [buffer], al ; Guardar el caracter ASCII en el buffer
Imprimir mensaje "Resultado: "
mov eax, 4
mov ebx, 1
mov ecx, msg
mov edx, 11
int 0x80
Imprimir el caracter numerico resultante
mov eax, 4
mov ebx, 1
mov ecx, buffer
mov edx, 1
int 0x80
Terminar el programa
mov eax, 1
xor ebx, ebx
int 0x80