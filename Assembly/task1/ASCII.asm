data segment
X db 0  
Y db 0                                      ;X,Y������������
data ends
 
code segment
assume cs:code,ds:data
start:
mov ah, 0
mov al, 3
int 10h
mov ax,0B800h
mov es,ax                                     ;es��ӳ���ַ   
mov ax,data
mov ds,ax
mov ch,0                                      ;ch��¼��������ASCII��
mov si,offset X
mov bp,offset Y

again1:
mov ah,0
mov al,ds:[bp]
mov dx,80
mul dx
mov dl,ds:[si]
mov dh,0
add ax,dx
mov dx,2
mul dx                                        ;�������������ʼֵ
mov bx,ax
mov al,ch                   
mov ah,0Ch                                    ;���ڵ׺������ASCII���Ӧ���ַ�
mov word ptr es:[bx],ax

mov dx,2
mov al,ch

again2:
push dx
mov cl,4
mov ah,0
rol al,cl                                      ;alѭ������4λ
push ax                                        ;����ax(al)��ǰֵ
and  al,0Fh
cmp  al,10
jb is_digit
is_alpha:
sub al,10
add al,'A'
jmp finish_2bits
is_digit:
add al,'0'
finish_2bits:
mov ah,0Ah
add bx,2
mov word ptr es:[bx],ax
pop ax
pop dx
sub dx,1
jnz again2

add ch,1                                    
mov al,ds:[bp]
add al,1
mov ds:[bp],al
cmp al,25
je  s2
cmp ch,0
je  end0
jmp again1



s2:
mov al,0
mov ds:[bp],al
mov al,ds:[si]
add al,7                               ;����������
mov ds:[si],al
cmp ch,0                               
je  end0
jmp again1




end0:
mov ah,0
int 16h
mov ah,4Ch
int 21h

code ends
end start















