from math import *

def checkio(data):
    eps = 10e-4
    x1 = int(data[1])
    y1 = int(data[3])
    x2 = int(data[7])
    y2 = int(data[9])
    x3 = int(data[13])
    y3 = int(data[15])
    e = 2 * (x2 - x1);
    f = 2 * (y2 - y1);
    g = x2*x2 - x1*x1 + y2*y2 - y1*y1;
    a = 2 * (x3 - x2);
    b = 2 * (y3 - y2);
    c = x3*x3 - x2*x2 + y3*y3 - y2*y2;
    X = (g*b - c*f) / (e*b - a*f);
    Y = (a*g - c*e) / (a*f - b*e);
    R = sqrt((X-x1)*(X-x1)+(Y-y1)*(Y-y1));
    X = round(X, 2)
    Y = round(Y, 2)
    R = round(R, 2)
    r = "(x-{:g})^2+(y-{:g})^2={:g}^2".format(X, Y, R)
    return r

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio("(2,2),(6,2),(2,6)") == "(x-4)^2+(y-4)^2=2.83^2"
    assert checkio("(3,7),(6,9),(9,7)") == "(x-6)^2+(y-5.75)^2=3.25^2"
