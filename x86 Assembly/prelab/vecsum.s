; _vecsum.s
;
; Purpose : This file contains the implementation of the function
;           vecsum, which adds up a vector of integers.
;
; Parameter 1 (in rdi) is the starting address of a sequence of 64-bit longs
; Parameter 2 (in rsi) is the number of integers in the sequence
; Return value is a long that is the sum of the integers in the sequence
;

	global _vecsum

	section .text

_vecsum:
	; Standard prologue: we do not have to create any local
	; variables (those values will be kept in registers), and 
	; we are not using any callee-saved registers.

	; Subroutine body:
	xor	rax, rax	 ; zero out the return register
	xor	r10, r10	 ; zero out the counter i
start:	
	cmp	r10, rsi	 ; does i == n?
	je	done		 ; if so, we are done with the loop
	add	rax, [rdi+8*r10] ; add a[i] to rax
	inc	r10		 ; increment our counter i
	jmp	start		 ; we are done with this loop iteration
done:	

	; Standard epilogue: the return value is already in rax, we
	; do not have any callee-saved registers to restore, and we do not
	; have any local variables to deallocate, so all we do is return
	ret



 	; THE BELOW TEXT IS THE BODY OF MATHLIB.S



	call _power
	cmp r10, r12    ; see if equals
	je done 		; jump to the end if they are equivalent
	dec r12
	mov rsi, rax
	call _product 	; carries out the product subroutine
	ret 			; it seems like it has something to do with the fact that every thing is yucked up in the prologue area


	_power:
 	; Prologue: Again, I do not think that I need any local variables
 	push rbp
 	mov rbp, rsp
 	push rsi

 	xor rax, rax

 	mov rsi, [rbp+8]
 	mov rcx, [rbp+12]

 	cmp rcx, 0
 	je power_loop
 	mov rax, 1
 	jmp power_done

power_loop:
	dec rcx
	push rcx
	push rsi
	call _power
	push rax
	push rsi 
	call _product

power_done: 
	; Epilogue: return the value in rax now
	pop rsi
	mov rsp, rbp
	pop rbp
	ret