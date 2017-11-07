import sympy as sy
import function as func
import re
from tkinter import *

root = Tk()
root.title('查询身高体重')
root.maxsize(450, 300)
root.minsize(450, 300)
#photo = PhotoImage(file="1.gif")
#imgLabel = Label(root, image = photo).grid()
label1 = Label(root,text = "请输入生日：", font = ("楷体", 15)).grid(row = 0, padx = 30, pady = 10)
Label2 = Label(root, text = "请输入性别：", font = ("楷体", 15)).grid(row = 1,padx = 30, pady = 10)
Label3 = Label(root, text = "请输入身高：", font = ("楷体", 15)).grid(row = 2,padx = 30, pady = 10)
Label4 = Label(root, text = "请输入体重：", font = ("楷体", 15)).grid(row = 3,padx = 30, pady = 10)
v1 = StringVar()
v2 = StringVar()
v3 = StringVar()
v4 = StringVar()
e1 = Entry(root, textvariable =v1, width = 30).grid(row = 0, column = 1)
e2 = Entry(root, textvariabl = v2, width = 30).grid(row = 1, column = 1)
e3 = Entry(root, textvariabl = v3, width = 30).grid(row = 2, column = 1)
e4 = Entry(root, textvariabl = v4, width = 30).grid(row = 3, column = 1)
text = Text(root, width = 30, height = 4)
text.grid(row=4, column = 1, pady = 30)
k = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 15, 18, 21, 24, 27, 30,
     33, 36, 39, 42, 45, 48, 51, 54, 57, 60, 63, 66, 69, 72, 75, 78, 81]
x = sy.Symbol('x')
p = re.compile(r'[2][0][1][0-7]/[1-9][012]{0,1}/[1-9][0-9]{0,1}') #编译正则表达式生成模式对象匹配时间的输入是否正确

def show():
    vs = v1.get()
    if(p.match(vs)==None):
        text.config(state=NORMAL)
        text.delete(1.0, END)
        text.insert(INSERT, '输入有误，请重新输入！\n')
        text.config(state=DISABLED)
        return
    vs = vs.split('/')
    month = int(vs[1])
    year = int(vs[0])
    day = int(vs[2])
    if(month >12 or day >31):
        text.config(state=NORMAL)
        text.delete(1.0, END)
        text.insert(INSERT, '输入有误，请重新输入！\n')
        text.config(state=DISABLED)
        return
    monage = (2017 - year) * 12 + (11 - month) + day / 30
    for i in range(35):
        if k[i] <= monage and k[i+1] > monage:
            break
    text.config(state = NORMAL)         #显示前设置text为可修改
    text.delete(1.0, END)
    if(v2.get() == '男'):
        text.insert(INSERT, '标准身高为：%.1f\n' % round(func.height_boy[i].subs(x, monage), 1))
        text.insert(INSERT, '标准体重为：%.1f\n' % round(func.weight_boy[i].subs(x, monage), 1))
        evaluate_boy(monage, i)
    elif(v2.get() == '女'):
        text.insert(INSERT, '标准身高为：%.1f\n' % round(func.height_girl[i].subs(x, monage), 1))
        text.insert(INSERT, '标准体重为：%.1f\n' % round(func.weight_girl[i].subs(x, monage), 1))
        evaluate_girl(monage, i)
    else:
        text.insert(INSERT, '输入有误，请重新输入！')
    text.config(state = DISABLED)          #显示后设置text为只读模式(不允许用户删改其内容)

def evaluate_boy(a, i):
    if(v3.get() != ''):           #身高的输入非空
        h = int(v3.get())
        h_minus3 = round(func.height_boy_minus3[i].subs(x, a), 1)
        h_minus2 = round(func.height_boy_minus2[i].subs(x, a), 1)
        h_minus1 = round(func.height_boy_minus1[i].subs(x, a), 1)
        h_plus1 = round(func.height_boy_plus1[i].subs(x, a), 1)
        h_plus2 = round(func.height_boy_plus2[i].subs(x, a), 1)
        h_plus3 = round(func.height_boy_plus3[i].subs(x, a), 1)
        if(h >= h_minus1 and h <= h_plus1):
            text.insert(INSERT, '身高属于正常范围\n')
        elif(h <= h_minus1 and h >=  h_minus2):
            text.insert(INSERT, '偏矮\n')
        elif(h >= h_plus1 and h <=  h_plus2):
            text.insert(INSERT, '偏高\n')
        elif(h >= h_minus3 and h <= h_minus2):
            text.insert(INSERT, '矮\n')
        elif (h <= h_plus3 and h >= h_plus2):
            text.insert(INSERT, '高\n')
        elif(h <= h_minus3):
            text.insert(INSERT, '你也太矮了\n')
        elif (h >= h_minus3):
            text.insert(INSERT, '你也太高了\n')
        else:
            pass
    if (v4.get() != ''):  # 体重的输入非空
        w = int(v4.get())
        w_minus3 = round(func.weight_boy_minus3[i].subs(x, a), 1)
        w_minus2 = round(func.weight_boy_minus2[i].subs(x, a), 1)
        w_minus1 = round(func.weight_boy_minus1[i].subs(x, a), 1)
        w_plus1 = round(func.weight_boy_plus1[i].subs(x, a), 1)
        w_plus2 = round(func.weight_boy_plus2[i].subs(x, a), 1)
        w_plus3 = round(func.weight_boy_plus3[i].subs(x, a), 1)
        if (w >= w_minus1 and w <= w_plus1):
            text.insert(INSERT, '体重属于正常范围\n')
        elif (w <= w_minus1 and w >= w_minus2):
            text.insert(INSERT, '偏轻\n')
        elif (w >= w_plus1 and w <= w_plus2):
            text.insert(INSERT, '偏重\n')
        elif (w >= w_minus3 and w <= w_minus2):
            text.insert(INSERT, '轻\n')
        elif (w <= w_plus3 and w >= w_plus2):
            text.insert(INSERT, '重\n')
        elif (w <= w_minus3):
            text.insert(INSERT, '你也太轻了\n')
        elif (w >= w_minus3):
            text.insert(INSERT, '你也太重了\n')
        else:
            pass

def evaluate_girl(a, i):
    if(v3.get() != ''):           #身高的输入非空
        h = int(v3.get())
        h_minus3 = round(func.height_girl_minus3[i].subs(x, a), 1)
        h_minus2 = round(func.height_girl_minus2[i].subs(x, a), 1)
        h_minus1 = round(func.height_girl_minus1[i].subs(x, a), 1)
        h_plus1 = round(func.height_girl_plus1[i].subs(x, a), 1)
        h_plus2 = round(func.height_girl_plus2[i].subs(x, a), 1)
        h_plus3 = round(func.height_girl_plus3[i].subs(x, a), 1)
        if(h >= h_minus1 and h <= h_plus1):
            text.insert(INSERT, '身高属于正常范围\n')
        elif(h <= h_minus1 and h >=  h_minus2):
            text.insert(INSERT, '偏矮\n')
        elif(h >= h_plus1 and h <=  h_plus2):
            text.insert(INSERT, '偏高\n')
        elif(h >= h_minus3 and h <= h_minus2):
            text.insert(INSERT, '矮\n')
        elif (h <= h_plus3 and h >= h_plus2):
            text.insert(INSERT, '高\n')
        elif(h <= h_minus3):
            text.insert(INSERT, '你也太矮了\n')
        elif (h >= h_minus3):
            text.insert(INSERT, '你也太高了\n')
        else:
            pass
    if (v4.get() != ''):  # 体重的输入非空
        w = int(v4.get())
        w_minus3 = round(func.weight_girl_minus3[i].subs(x, a), 1)
        w_minus2 = round(func.weight_girl_minus2[i].subs(x, a), 1)
        w_minus1 = round(func.weight_girl_minus1[i].subs(x, a), 1)
        w_plus1 = round(func.weight_girl_plus1[i].subs(x, a), 1)
        w_plus2 = round(func.weight_girl_plus2[i].subs(x, a), 1)
        w_plus3 = round(func.weight_girl_plus3[i].subs(x, a), 1)
        if (w >= w_minus1 and w <= w_plus1):
            text.insert(INSERT, '体重属于正常范围\n')
        elif (w <= w_minus1 and w >= w_minus2):
            text.insert(INSERT, '偏轻\n')
        elif (w >= w_plus1 and w <= w_plus2):
            text.insert(INSERT, '偏重\n')
        elif (w >= w_minus3 and w <= w_minus2):
            text.insert(INSERT, '轻\n')
        elif (w <= w_plus3 and w >= w_plus2):
            text.insert(INSERT, '重\n')
        elif (w <= w_minus3):
            text.insert(INSERT, '你也太轻了\n')
        elif (w >= w_minus3):
            text.insert(INSERT, '你也太重了\n')
        else:
            pass

b = Button(root, text = "查 询", font = ("楷体"), width = 15, command = show).grid(row = 4, pady = 30)

mainloop()