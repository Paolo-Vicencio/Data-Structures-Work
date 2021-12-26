; threexplusone.s

	global threexplusone


threexplusone:
	; Beginning

start:
	inc rax
	cmp rdi, 1
	ja done

	test rdi, 1
	jz even
	test rdi, 1
	jnz odd

even:
	shr rdi, 1
	push rdi
	call threexplusone
	pop rdi

odd:
	shl rdi, 1
	lea rdi, [rdi + rdi*2]
	push rdi
	call threexplusone
	pop rdi

done:
	ret