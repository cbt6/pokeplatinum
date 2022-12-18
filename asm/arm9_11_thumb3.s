
	.include "macros/function.inc"
	.include "include/arm9_11_thumb3.inc"

	.text

	thumb_func_start sub_020BBBE4
sub_020BBBE4: ; 0x020BBBE4
	stmia r0!, {r1}
	mov r1, #0
	str r3, [r0, #0x1c]
	mov r3, #0
	stmia r0!, {r1, r3}
	stmia r0!, {r1, r2, r3}
	mov r2, #0
	stmia r0!, {r1, r3}
	add r0, #4
	stmia r0!, {r1, r2, r3}
	bx lr
	; .align 2, 0
	thumb_func_end sub_020BBBE4
