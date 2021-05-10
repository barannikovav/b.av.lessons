
global start					
N equ 100	
default rel						
							
				
section .bss						

var_read:	resb N					
var_write:	resb N					
							
section .text						
start:							
	call asm_read_decimal				
							
			
	call asm_write
	call asm_exit					

asm_read_decimal:					
	call asm_read								
	
	lea rsi, [var_read]
	lea rax, [var_write]
	
	mov rcx, N					
	l_rd:						
											
		mov rdx, N
		sub rdx, rcx				
		xor rbx, rbx				
		mov bl, [rsi + rdx]		
		
		cmp bl, 65
		jb NS
		cmp bl, 91
		jb BS 
		cmp bl, 97
		jb NS	
		cmp bl, 123
		jb TS	
		jae NS		
		
		
		
		TS:
		mov byte[rax + rdx], bl
		sub byte[rax + rdx], 32
		jmp LL
		BS:
		mov byte[rax + rdx], bl
		add byte[rax + rdx], 32
		jmp LL
		NS:
		mov byte[rax + rdx], bl
		
		LL:

		loop l_rd				
	ret						

		

asm_read:						
	mov rax, 0					
	mov rdi, 0					
							
	mov rsi, var_read				
	mov rdx, N					
	syscall						
	ret						

asm_write:						
	mov rax, 1					
	mov rdi, 1					
	mov rsi, var_write			
	mov rdx, N					
	syscall						
	ret

asm_exit:						
	mov rax, 60					
	xor rdi, rdi					
	syscall
	ret
