.386
data segment use16       ;16位数*16位数,结果位32位
operand1 db 17           ;允许输入的最多字符数
         db ?            ;实际输入的字符数
	 db 17 dup(0)  ;保存输入的字符，最后回车符也会占用一个字节
operand2 db 17    
         db ?
         db 17 dup(0)
                         ;operand1和operand2分别记录从键盘读入的两个操作数
s1 db 10 dup(" "), 0Dh, 0Ah, "$"    ;s1记录计算结果十进制各位数值，最大为十位数
s2 db 8 dup(" "), 0Dh, 0Ah, "$"    ;s1记录计算结果十六进制各位数值，最大为八位数
s3 db 32 dup(" "), 0Dh, 0Ah, "$"    ;s1记录计算结果二进制各位数值，最大为三十二位数
message1 db "Please enter the first operation:", 0Dh, 0Ah, "$"          ;输入提示语句
message2 db "Please enter the second operation:", 0Dh, 0Ah, "$"         ;输入提示语句
message3 db "The result is:", 0Dh, 0Ah, "$"                             ;输出结果提示语句
message4 db "Decimal system:", "$"
message5 db "Hexadecimal:", "$"
message6 db "Binary system:", "$"


data ends
code segment use16
assume cs:code, ds:data
main:
    mov ax, data
    mov ds, ax 
    mov ah, 0
    mov al, 3                         ;读取之前先清屏
    int 10h
    mov ah, 9
    lea dx, message1                  
    int 21h                           ;第一条输入提示语句
    mov ah, 0Ah
    mov dx, offset operand1           ;读第一个操作数
    int 21h
    mov ah, 2
    mov dl, 0Dh                  ;回车
    int 21h              
    mov ah, 2
    mov al, 0Ah                    
    int 21h                      ;换行
    mov di, 2
    mov cl, operand1[1]           ;实际输入的字符数
    
again1:
    sub operand1[di], 30h               ;字符转数值
    inc di
    dec cl
    jnz again1
    
    mov ah, 0
    mov al, 3
    int 10h                           ;读之前清屏
    mov ah, 9
    lea dx, message2 
    int 21h
    mov ah, 0Ah
    mov dx, offset operand2           ;读第二个操作数
    int 21h
    mov ah, 2
    mov dl, 0Dh                  ;回车
    int 21h              
    mov ah, 2
    mov al, 0Ah                    
    int 21h                      ;换行
    mov di, 2
    mov cl, operand2[1]            ;实际输入的字符数

again2:
    sub operand2[di], 30h               ;字符转数值
    inc di
    dec cl
    jnz again2

    mov cl, 10
    mov ah, 0
    mov al, operand1[2]
    mov bx, 3
    mov dh, 0
 next1:
    mov dl, operand1[bx]
    cmp dl, 0Dh
    je  second                    ;读完第一个数转读第二个数
    imul cl                      ;ax=al*10                    
    add ax, dx
    inc bx
    jmp next1

second:
    mov bx, ax                   ;在读第二个数前，先把第一个数转存到寄存器bx(注：第一个数的十进制值不会超过16位)
    push bx                      ;先把bx保护起来
    mov cl,10
    mov ah, 0
    mov al, operand2[2]
    mov bx, 3
    mov dh, 0
next2:                           ;读第二个数
    mov dl, operand2[bx]
    cmp dl, 0Dh                  ;用回车判断读取是否结束
    je  multi                    ;读完则进行乘法运算
    imul cl 
    add ax, dx                   ;第二个数在寄存器ax中
    inc bx
    jmp next2
multi:                           ;进行乘法运算，运算结果最高为32位
    pop bx                       ;释放bx的原值
    mul bx                       ;dx:ax存了运算结果
    
    mov cl,16
    push ax
    mov eax, 0
    mov ax,dx                    ;破坏了ax的值
    shl eax,cl                   ;左移16位把dx存到eax的高16位去
    pop ax                       ;eax=ds:ax
              
    

decimal:                         ;十进制
    mov cx, 0                    ;统计push次数
    mov di, 0                    ;数组下标
    push eax
again_1:
    mov edx, 0                   ;被除数为edx：eax
    mov ebx,10
    div ebx                      ;eax=商，edx=余数
    add dl,'0'                   ;数字转ASCII码
    push dx
    inc cx
    cmp eax,0
    jne again_1
pop_again1:
    pop dx
    mov s1[di], dl
    inc di
    dec cx
    jnz pop_again1
    pop eax

hexadecimal:                         ;16进制
    mov cx, 0                    ;统计push次数
    mov di, 0                    ;数组下标
    push eax
again_2:
    mov edx, 0                   ;被除数为edx：eax
    mov ebx,16
    div ebx                      ;eax=商，edx=余数
    cmp dl,9
    ja  is_letter                
is_digit:
    add dl,'0'                   ;数字转ASCII码
    push dx
    inc cx
    jmp next
is_letter:
    sub dl,10
    add dl,'A'
    push dx
    inc cx
next:
    cmp eax,0                     ;比较整除结果，判断是否进行下次除法
    jne again_2
pop_again2:
    pop dx
    mov s2[di], dl
    inc di
    dec cx
    jnz pop_again2
    pop eax

binary:                         ;二进制
    mov cx, 0                    ;统计push次数
    mov di, 0                    ;数组下标
    push eax
again_3:
    mov edx, 0                   ;被除数为edx：eax
    mov ebx,2
    div ebx                      ;eax=商，edx=余数
    add dl,'0'                   ;数字转ASCII码
    push dx
    inc cx
    cmp eax,0
    jne again_3
pop_again3:
    pop dx
    mov s3[di], dl
    inc di
    dec cx
    jnz pop_again3
    pop eax

output:
    mov ah, 0
    mov al, 3                    ;输出结果之前先清屏
    int 10h
    mov ah, 9
    lea dx, message3                  
    int 21h                           ;结果输出提示语句
    mov ah, 9
    lea dx, message4                  
    int 21h                           ;提示输出10进制结果 
    mov ah, 9
    lea dx, s1
    int 21h
    mov ah, 2
    mov dl, 0Dh                  ;回车
    int 21h              
    mov ah, 2
    mov al, 0Ah                    
    int 21h                      ;换行
    mov ah, 9
    lea dx, message5                  
    int 21h                           ;提示输出16进制结果
    mov ah, 9
    lea dx, s2
    int 21h
    mov ah, 2
    mov dl, 0Dh                  ;回车
    int 21h              
    mov ah, 2
    mov al, 0Ah                    
    int 21h                      ;换行
    mov ah, 9
    mov ah, 9
    lea dx, message6                  
    int 21h                           ;提示输出2进制结果
    lea dx, s3
    int 21h
    mov ah, 2
    mov dl, 0Dh                  ;回车
    int 21h              
    mov ah, 2
    mov al, 0Ah                    
    int 21h                      ;换行
done:
    mov ah,4Ch
    int 21h
code ends
end main





    






    
