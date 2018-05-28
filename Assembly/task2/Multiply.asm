.386
data segment use16       ;16λ��*16λ��,���λ32λ
operand1 db 17           ;�������������ַ���
         db ?            ;ʵ��������ַ���
	 db 17 dup(0)  ;����������ַ������س���Ҳ��ռ��һ���ֽ�
operand2 db 17    
         db ?
         db 17 dup(0)
                         ;operand1��operand2�ֱ��¼�Ӽ��̶��������������
s1 db 10 dup(" "), 0Dh, 0Ah, "$"    ;s1��¼������ʮ���Ƹ�λ��ֵ�����Ϊʮλ��
s2 db 8 dup(" "), 0Dh, 0Ah, "$"    ;s1��¼������ʮ�����Ƹ�λ��ֵ�����Ϊ��λ��
s3 db 32 dup(" "), 0Dh, 0Ah, "$"    ;s1��¼�����������Ƹ�λ��ֵ�����Ϊ��ʮ��λ��
message1 db "Please enter the first operation:", 0Dh, 0Ah, "$"          ;������ʾ���
message2 db "Please enter the second operation:", 0Dh, 0Ah, "$"         ;������ʾ���
message3 db "The result is:", 0Dh, 0Ah, "$"                             ;��������ʾ���
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
    mov al, 3                         ;��ȡ֮ǰ������
    int 10h
    mov ah, 9
    lea dx, message1                  
    int 21h                           ;��һ��������ʾ���
    mov ah, 0Ah
    mov dx, offset operand1           ;����һ��������
    int 21h
    mov ah, 2
    mov dl, 0Dh                  ;�س�
    int 21h              
    mov ah, 2
    mov al, 0Ah                    
    int 21h                      ;����
    mov di, 2
    mov cl, operand1[1]           ;ʵ��������ַ���
    
again1:
    sub operand1[di], 30h               ;�ַ�ת��ֵ
    inc di
    dec cl
    jnz again1
    
    mov ah, 0
    mov al, 3
    int 10h                           ;��֮ǰ����
    mov ah, 9
    lea dx, message2 
    int 21h
    mov ah, 0Ah
    mov dx, offset operand2           ;���ڶ���������
    int 21h
    mov ah, 2
    mov dl, 0Dh                  ;�س�
    int 21h              
    mov ah, 2
    mov al, 0Ah                    
    int 21h                      ;����
    mov di, 2
    mov cl, operand2[1]            ;ʵ��������ַ���

again2:
    sub operand2[di], 30h               ;�ַ�ת��ֵ
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
    je  second                    ;�����һ����ת���ڶ�����
    imul cl                      ;ax=al*10                    
    add ax, dx
    inc bx
    jmp next1

second:
    mov bx, ax                   ;�ڶ��ڶ�����ǰ���Ȱѵ�һ����ת�浽�Ĵ���bx(ע����һ������ʮ����ֵ���ᳬ��16λ)
    push bx                      ;�Ȱ�bx��������
    mov cl,10
    mov ah, 0
    mov al, operand2[2]
    mov bx, 3
    mov dh, 0
next2:                           ;���ڶ�����
    mov dl, operand2[bx]
    cmp dl, 0Dh                  ;�ûس��ж϶�ȡ�Ƿ����
    je  multi                    ;��������г˷�����
    imul cl 
    add ax, dx                   ;�ڶ������ڼĴ���ax��
    inc bx
    jmp next2
multi:                           ;���г˷����㣬���������Ϊ32λ
    pop bx                       ;�ͷ�bx��ԭֵ
    mul bx                       ;dx:ax����������
    
    mov cl,16
    push ax
    mov eax, 0
    mov ax,dx                    ;�ƻ���ax��ֵ
    shl eax,cl                   ;����16λ��dx�浽eax�ĸ�16λȥ
    pop ax                       ;eax=ds:ax
              
    

decimal:                         ;ʮ����
    mov cx, 0                    ;ͳ��push����
    mov di, 0                    ;�����±�
    push eax
again_1:
    mov edx, 0                   ;������Ϊedx��eax
    mov ebx,10
    div ebx                      ;eax=�̣�edx=����
    add dl,'0'                   ;����תASCII��
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

hexadecimal:                         ;16����
    mov cx, 0                    ;ͳ��push����
    mov di, 0                    ;�����±�
    push eax
again_2:
    mov edx, 0                   ;������Ϊedx��eax
    mov ebx,16
    div ebx                      ;eax=�̣�edx=����
    cmp dl,9
    ja  is_letter                
is_digit:
    add dl,'0'                   ;����תASCII��
    push dx
    inc cx
    jmp next
is_letter:
    sub dl,10
    add dl,'A'
    push dx
    inc cx
next:
    cmp eax,0                     ;�Ƚ�����������ж��Ƿ�����´γ���
    jne again_2
pop_again2:
    pop dx
    mov s2[di], dl
    inc di
    dec cx
    jnz pop_again2
    pop eax

binary:                         ;������
    mov cx, 0                    ;ͳ��push����
    mov di, 0                    ;�����±�
    push eax
again_3:
    mov edx, 0                   ;������Ϊedx��eax
    mov ebx,2
    div ebx                      ;eax=�̣�edx=����
    add dl,'0'                   ;����תASCII��
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
    mov al, 3                    ;������֮ǰ������
    int 10h
    mov ah, 9
    lea dx, message3                  
    int 21h                           ;��������ʾ���
    mov ah, 9
    lea dx, message4                  
    int 21h                           ;��ʾ���10���ƽ�� 
    mov ah, 9
    lea dx, s1
    int 21h
    mov ah, 2
    mov dl, 0Dh                  ;�س�
    int 21h              
    mov ah, 2
    mov al, 0Ah                    
    int 21h                      ;����
    mov ah, 9
    lea dx, message5                  
    int 21h                           ;��ʾ���16���ƽ��
    mov ah, 9
    lea dx, s2
    int 21h
    mov ah, 2
    mov dl, 0Dh                  ;�س�
    int 21h              
    mov ah, 2
    mov al, 0Ah                    
    int 21h                      ;����
    mov ah, 9
    mov ah, 9
    lea dx, message6                  
    int 21h                           ;��ʾ���2���ƽ��
    lea dx, s3
    int 21h
    mov ah, 2
    mov dl, 0Dh                  ;�س�
    int 21h              
    mov ah, 2
    mov al, 0Ah                    
    int 21h                      ;����
done:
    mov ah,4Ch
    int 21h
code ends
end main





    






    
