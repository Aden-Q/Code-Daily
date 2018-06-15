from math import *
def longest_palindromic(text):
    rtext =""
    maxlength = -2
    for i in range(len(text)):
        for j in range(i,len(text)):
            rflag = True
            for k in range(floor((j-i+1)/2)):
                if(text[i+k]!=text[j-k]):
                    rflag = False
                    break
            if rflag == True and j + 1 - i > maxlength:
                rtext = text[i:j+1]
                maxlength = j + 1 - i
            
    return rtext

if __name__ == '__main__':
    assert longest_palindromic("artrartrt") == "rtrartr", "The Longest"
    assert longest_palindromic("abacada") == "aba", "The First"
    assert longest_palindromic("aaaa") == "aaaa", "The A"
