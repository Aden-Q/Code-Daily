def checkio(text):

    #replace this for solution
    a=text[:].lower()
    b=set(a)
    count=0
    alp='z'
    
    for i in b:
        if i.isalpha()==False:
            continue
        elif a.count(i)>count:
            count=a.count(i)
            alp=i
        elif a.count(i)==count and i<alp:
            alp=i
    return alp

if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert checkio("Hello World!") == "l", "Hello test"
    assert checkio("How do you do?") == "o", "O is most wanted"
    assert checkio("One") == "e", "All letter only once."
    assert checkio("Oops!") == "o", "Don't forget about lower case."
    assert checkio("AAaooo!!!!") == "a", "Only letters."
    assert checkio("abe") == "a", "The First."
    print("Start the long test")
    assert checkio("a" * 9000 + "b" * 1000) == "a", "Long."
    print("The local tests are done.")
