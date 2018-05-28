def checkio(words):
    #return True or False
    h=words.split()
    
    count=0
    for i in h:
        flag=0
        for j in range(len(i)):
            if i[j].isalpha()==False:
                count=0
                flag=1
        if flag==0:
            count+=1
        if count>=3:
            break
    if count>=3:
        return True
    return False

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio("Hello World hello") == True, "Hello"
    assert checkio("He is 123 man") == False, "123 man"
    assert checkio("1 2 3 4") == False, "Digits"
    assert checkio("bla bla bla bla") == True, "Bla Bla"
    assert checkio("Hi") == False, "Hi"
    print("Coding complete? Click 'Check' to review your tests and earn cool rewards!")
