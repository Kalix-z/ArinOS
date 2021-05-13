[bits 32]

StartingString:
  mov [0xb8000], byte 'T' ;0xb8000 is the video memory address 
  mov [0xb8002], byte 'e'
  mov [0xb8004], byte 'r'
  mov [0xb8006], byte 'm'
  mov [0xb8008], byte 'i'
  mov [0xb800a], byte 'n'
  mov [0xb800c], byte 'a'
  mov [0xb800e], byte 'l'
  mov [0xb8012], byte '$'
  jmp $




