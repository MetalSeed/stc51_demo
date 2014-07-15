org 0000h
mov p0,#0x3f
mov p2,#0
main:   mov r7,#0ffh
wait1:  jb p3.2,wait1    ;按键没有按下，等待
	call del10ms   ;调用延时
	jb p3.2,wait1  ;继续查询
	ljmp play1
play1:  inc r7
	mov a,r7
	mov dptr,#tab
	movc a,@a+dptr
	mov p0,a       ;查表显示数字
wait2:  jnb p3.2,wait2    ;等待按键弹起
	cjne a,#6fh,wait1 ;判断是否显示到最后一个数字
	ljmp main
	ret
tab:    db 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f  
del10ms:mov r6,#14h
del1:   mov r5,#0ffh
del2:   djnz r5,del2
	djnz r6,del1
	ret
	end
