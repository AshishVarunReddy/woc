bits 32
section .data
str: db "Hello World", 0xa, 0
section .text
global _start
_start:
write:
   mov eax, 4
   mov ebx, 1
   mov ecx, str
   mov edx, 12
   int 0x80


exit:
   mov eax, 1
   mov ebx, 0
   int 0x80

