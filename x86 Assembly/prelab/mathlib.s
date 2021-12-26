; Paolo Vicencio, pjv7nd, 4/12/21, _mathlib.s
; Purpose: This file contains the implementation of the function mathlib, which has
; 			two subroutines: taking two values and multiplying them and then taking those
; 			two values and putting one to the power of another
; Parameter 1 (in rdi) is the first integer
; Parameter 2 (in rsi) is the second integer
; Return value is different for both functions, but it will always be an integer


	global product
	global power
	section .text

product:
	; Prologue: I do not think there are any local variables? The only thing
	; 			would be an incrementing value, but I think that does not
	; 			need to be declared

	xor rax, rax	; zero out the return register
	xor r10, r10 	; zero out the counter i 

start:
	cmp r10, rsi 	; checks to see if the increment variable i is equal to n
	je done			; if it is, we are done with the loop
	add rax, rdi 	; adds the rsi register to the rax register, which is to add the first integer into the return register
	inc r10 		; increments the counter by 1
	jmp start 		; jumps back to the beginning of the loop
done: 
	; Epilogue: basically just need to return the rax value from the register now
	ret


power:
 	; Prologue: Again, I do not think that I need any local variables
; set up
	xor rax, rax
	inc rax


start2: 
; base case
 	cmp rsi, 0
 	je done2
 	dec rsi
 	call power
 	mov rsi, rax
 	call product
 	ret


done2: 
	; Epilogue: return the value in rax now
	ret







