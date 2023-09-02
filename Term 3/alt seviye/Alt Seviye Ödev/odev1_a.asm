stk segment para stack 'stk'
    dw 64 dup(?)
stk ends

dts segment para 'dts'
dts ends

cds segment para 'cds'
    assume cs:cds, ds:dts, ss:stk

    dnum proc far
        push bp
        push ax
        push cx
        push bx

        mov bp, sp
        mov ax, [bp+12]
        cmp ax, 3
        jae func
        cmp ax, 0
        jnz not_zero
        mov word ptr [bp+12], 0
        jmp end_func
        not_zero:
        mov word ptr [bp+12], 1
        jmp end_func
        func:
        ; d(n-1)
        push ax ; push to stack n
        dec ax
        push ax ; push to stack n-1
        call far ptr dnum
        pop bx ; pop d(n-1) from stack
        pop ax ; pop n from stack
        ; d(d(n-1))
        push bx ; push d(n-1) to stack
        call far ptr dnum
        pop bx ; pop d(d(n-1)) from stack
        ; d(n-2)
        push ax ; push to stack n
        sub ax, 2
        push ax ; push n-2
        call far ptr dnum
        pop cx ; pop d(n-2)
        pop ax ; pop n
        ; d(n-1-d(n-2))
        push ax ; push n
        dec ax
        sub ax, cx
        push ax ; push n-1-d(n-2)
        call far ptr dnum
        pop cx ; pop d(n-1-d(n-2))
        pop ax ; pop n
        ; d(d(n-1)) + d(n-1-d(n-2))
        add bx, cx
        mov [bp+12], bx
        end_func:
        pop bx
        pop cx
        pop ax
        pop bp
        retf
    dnum endp

    printint proc far
        push bp
        push ax
        push cx
        push dx
        push di
        mov bp, sp
        mov ax, [bp+14]
        mov cx, 4
        mov di, 0
        digit_loop:
        xor dx, dx
        mov dh, 10
        div dh ; ah <- remainder, al <- quotient 
        mov dl, ah
        push dx ; pushes the right most digit to stack
        inc di
        xor ah, ah
        cmp al, 0
        loopnz digit_loop
        mov cx, di
        print_loop:
        pop dx ; pops every digit from stack to print
        add dl, 48
        mov ah, 2
        int 21h
        loop print_loop
        mov dl, 32 ;space between numbers
        int 21h
        pop di
        pop dx
        pop cx
        pop ax
        pop bp
        retf
    printint endp

    main proc far
        push ds
        xor ax, ax
        push ax

        mov ax, dts
        mov ds, ax

        mov di, 10
        push di
        call far ptr dnum
        call far ptr printint
        pop dx
        retf
    main endp
cds ends
    end main