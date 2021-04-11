global _start
flags equ 0x42

N2 equ 1

section .bss
	var_fd: resq N2

section .text

_start:

call asm_open_file

call asm_write_chess_desk_8x8_in_file

call asm_close_file

call asm_exit

;--------------------------------------------------------------------------------

asm_write_chess_desk_8x8_in_file:
mov r10, 4

PRINT_8x8:
	call asm_write_zero_first_in_file
	call asm_write_one_first_in_file
	
	dec r10

	cmp r10, 0
	ja PRINT_8x8
	jbe EXIT_8x8
	
	EXIT_8x8:

	ret

;--------------------------------------------------------------------------------

asm_write_zero_first_in_file:
	mov rax, 1
	mov rdi, [var_fd]
	mov rsi, string_zero_first
	mov rdx, 9
	syscall

	ret

;--------------------------------------------------------------------------------

asm_write_one_first_in_file:
	mov rax, 1
	mov rdi, [var_fd]
	mov rsi, string_one_first
	mov rdx, 9
	syscall

	ret

;--------------------------------------------------------------------------------

asm_open_file:

mov rax, 2
mov rdi, name
mov rsi, flags
syscall

mov [var_fd], rax

ret

;--------------------------------------------------------------------------------

asm_close_file:

mov rax, 3
mov rdi, [var_fd]
syscall
ret

;--------------------------------------------------------------------------------

asm_exit:						
	mov rax, 60					
	xor rdi, rdi					
	syscall
	ret


name: 	db	"1.txt", 0

string_zero_first: db "01010101", 10
string_one_first: db "10101010", 10