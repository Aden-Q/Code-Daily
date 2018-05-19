def checkio(data):

    #replace this for solution
    if len(data)<10:
        return False
    flag1=0
    flag2=0
    flag3=0
    s_u='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    s_l=s_u.lower()
    s='0123456789'
    for i in s_u:
        if i in data:
            flag1=1
    for i in s_l:
        if i in data:
            flag2=1
    for i in s:
        if i in data:
            flag3=1  
    if flag1 and flag2 and flag3:
        return True
    return False
    
    
    

#Some hints
#Just check all conditions


if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert checkio('A1213pokl') == False, "1st example"
    assert checkio('bAse730onE4') == True, "2nd example"
    assert checkio('asasasasasasasaas') == False, "3rd example"
    assert checkio('QWERTYqwerty') == False, "4th example"
    assert checkio('123456123456') == False, "5th example"
    assert checkio('QwErTy911poqqqq') == True, "6th example"
    print("Coding complete? Click 'Check' to review your tests and earn cool rewards!")
