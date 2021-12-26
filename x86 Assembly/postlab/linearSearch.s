	; Paolo Vicencio, pjv7nd, 4/15/21, linearSearch.s

	global linearSearch

linearSearch:
	xor r10,r10
start:
	cmp r10, rsi
	je notfound
	inc r10
	cmp edx, [rdi+4*r10]
	je found
	jmp start

notfound:
	mov rax, -1
	ret

found:
	mov rax, r10
	ret