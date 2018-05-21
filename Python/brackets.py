def checkio(expression):
    a=[]        #initialize an empty list
    for i in expression:
        if i=='{' or i=='(' or i=='[':
            a.append(i)
        elif i=='}':
            if a==[]:
                return False
            elif a[-1]=='{':
                a.pop()
            else:
                return False
        elif i==')':
            if a==[]:
                return False
            elif a[-1]=='(':
                a.pop()
            else:
                return False
        elif i==']':
            if a==[]:
                return False
            elif a[-1]=='[':
                a.pop()
            else:
                return False
        else:
            pass
    if a==[]:
        return True
    return False

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio("((5+3)*2+1)") == True, "Simple"
    assert checkio("{[(3+1)+2]+}") == True, "Different types"
    assert checkio("(3+{1-1)}") == False, ") is alone inside {}"
    assert checkio("[1+1]+(2*2)-{3/3}") == True, "Different operators"
    assert checkio("(({[(((1)-2)+3)-3]/3}-3)") == False, "One is redundant"
    assert checkio("2+3") == True, "No brackets, no problem"
