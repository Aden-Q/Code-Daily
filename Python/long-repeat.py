def long_repeat(line):
    """
        length the longest substring that consists of the same char
    """
    # your code here
    maxcount=0
    curcount=1

    if line=='':
        return 0
    for i in range(len(line)):
        j=i+1
        if j<len(line):
            if(line[j]==line[i]):
                curcount+=1
            else:
                curcount=1
        if curcount>maxcount:
            maxcount=curcount
    return maxcount
if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert long_repeat('sdsffffse') == 4, "First"
    assert long_repeat('ddvvrwwwrggg') == 3, "Second"
    assert long_repeat('abababaab') == 2, "Third"
    assert long_repeat('') == 0, "Empty"
    print('"Run" is good. How is "Check"?')
