ORG 100h          ; origin for .COM file

MOV AL, 07h       ; Number to check (change as needed)
AND AL, 01h       ; Check LSB
JZ EVEN           ; If zero → even

; --- Odd case ---
MOV DX, OFFSET ODD_MSG
CALL PRINT_STRING
JMP END_PROGRAM

EVEN:
MOV DX, OFFSET EVEN_MSG
CALL PRINT_STRING

END_PROGRAM:
MOV AH, 4Ch       ; terminate program
INT 21h

; --- Subroutine to print string ---
PRINT_STRING:
MOV AH, 09h
INT 21h
RET

; --- Messages ---
ODD_MSG DB 'Number is Odd$',0
EVEN_MSG DB 'Number is Even$',0

END
