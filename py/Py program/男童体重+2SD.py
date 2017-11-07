from sympy import *
a = []; b = []; c = []; d = []; x = []; f = []; y = []; p1 = []; p2 = []
x = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 60, 63, 66, 69, 72, 75, 78, 81]
f = [4.18, 5.67, 7.14, 8.4, 9.32, 9.99, 10.5, 10.93, 11.29, 11.64, 11.95, 12.26, 12.54, 13.32, 14.09, 14.9, 15.67, 16.38, 17.06, 17.72, 18.37, 19.02, 19.65,
     20.32, 21.01, 21.76, 22.57, 23.43, 24.38, 25.32, 26.24, 27.17, 28.03, 29.01, 30.13, 31.56]
for i in range(1, 36):
    a.append(Symbol('a%s' % i))
    b.append(Symbol('b%s' % i))
    c.append(Symbol('c%s' % i))
    d.append(Symbol('d%s' % i))
for i in range(34):
    y.append(a[i] * x[i] ** 3 + b[i] * x[i] ** 2 + c[i] * x[i] + d[i] - f[i])
    y.append(a[i] * x[i+1] ** 3 + b[i] * x[i+1] ** 2 + c[i] * x[i+1] + d[i] - f[i+1])
    y.append(a[i+1] * x[i+1] ** 3 + b[i+1] * x[i+1] ** 2 + c[i+1] * x[i+1] + d[i+1] - f[i+1])
    y.append(a[i+1] * x[i+2] ** 3 + b[i+1] * x[i+2] ** 2 + c[i+1] * x[i+2] + d[i+1] - f[i+2])
    y.append(3 * a[i+1] * x[i+1] ** 2 + 2 * b[i+1] * x[i+1]  + c[i+1] - 3 * a[i] * x[i+1] ** 2 - 2 * b[i] * x[i+1] - c[i])
    y.append(6 * a[i+1] * x[i+1] + 2 * b[i+1] - 6 * a[i] * x[i+1] - 2 * b[i])
for i in range(204):
    p1.append(y[i])
for i in range(35):
    p2.append(a[i])
    p2.append(b[i])
    p2.append(c[i])
    p2.append(d[i])
p1.append(6 * a[0] * x[0] + 2 * b[0])
p1.append(6 * a[34] * x[35] + 2 * b[34])
coe = solve(p1, p2)
g = []
x = Symbol('x')
for i in range(35):
    g.append(coe[a[i]] * x ** 3 + coe[b[i]] * x ** 2 + coe[c[i]] * x + coe[d[i]])
print(g)






