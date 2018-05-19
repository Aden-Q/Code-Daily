def safe_pawns(pawns):
    count=0
    
    for i in pawns:
        tmp1=chr(ord(i[0])-1)+str(int(i[1])-1)
        tmp2=chr(ord(i[0])+1)+str(int(i[1])-1)
        if tmp1 in pawns or tmp2 in pawns:
            count+=1
    return count

if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert safe_pawns({"b4", "d4", "f4", "c3", "e3", "g5", "d2"}) == 6
    assert safe_pawns({"b4", "c4", "d4", "e4", "f4", "g4", "e5"}) == 1
    print("Coding complete? Click 'Check' to review your tests and earn cool rewards!")
