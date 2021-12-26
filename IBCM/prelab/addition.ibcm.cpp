// Paolo Vicencio, pjv7nd, Lab 7, 4/4/21
mem locn	label	op		addr	comments

// SETTING UP THE VALUES AND INITIAL MEMORY 
C00A 000			jmp		start	skip around the declared variables
0000 001	x		dw		0		int x
0000 002	y		dw		0		int y
0000 003	z		dw		0		int z
0000 004 	sum		dw		0		int sum
0000 005	zero	dw		0						
0000 006							space for changes
0000 007
0000 008
0000 009

// READING IN AND STORING THE INITIAL VALUES
1000 00A	start 	read	x		read first integer input
4001 00B 			store	x		store first int into x value
1000 00C			read	y		read second integer input
4002 00D			store 	y		store second int into y value
1000 00E			read 	z		read third integer input
4003 00F			store	z		store third int into z value

// LOAD? IN VALUES AND ADD TO EACH OTHER TO CREATE FINAL SUM IN MEMORY SPOT 004
// 3004 010 			load 	sum 	load in the sum value (which is zero)
5001 010			add 	x 		add the value in memory 001 to whats in the accumulator (sum)
5002 011			add 	y 		add the value in memory 002 to whats in the accumulator (sum + x)
5003 012			add 	z 		add the value in memory 003 to whats in the accumulatro (sum + x + y)
4004 013			store 	sum 	store the final value created into memory spot 004 (title sum)
// LOAD IN THE ACCUMULATOR AND CHECK ITS VALUE
3004 014 			load 	sum 	load in the value of memory spot 004 to the accumulator (should be the sum of all input values at this point)
D017 015			jmpe			if the value in the accumulator at this point is equal to 0, jump to memory spot 17
1800 016 			print 	sum 	prints out the value in the accumulator (the sum at this point)
C00A 017			jmp 			if this step is reached, the accumulator value is not 0 so we jump back to the beginning
1001 018			print  			print the value in the x/001 memory space
1002 019			print			print the value in the y/002 memory space
1003 01A			print 			print the value in the x/003 memory space
1800 01B 			print 	sum 	prints out the value in the accumulator (the sum at this point)