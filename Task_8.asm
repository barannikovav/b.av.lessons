	global start

	section .text

	start:

	call func
;--------------------------------------------------------------------------------------------Ы
	func:
	push 8
	push 7

	call sum

	add esp, 8

	mov dword [c], eax

	ret
;--------------------------------------------------------------------------------------------
	sum:

		push        ebp  
  	mov         ebp,esp 
  	sub         esp,0C0h 
  	push        ebx  
  	push        esi  
  	push        edi  
  	lea         edi,[ebp-0C0h] 
  	mov         ecx,30h 
  	mov         eax,0CCCCCCCCh 
  	rep stos    dword  [edi]

  	mov         eax,dword [a] 
  	add         eax,dword [b]

  	pop         edi  
  	pop         esi  
  	pop         ebx  
  	mov         esp,ebp 
  	pop         ebp  
  	ret