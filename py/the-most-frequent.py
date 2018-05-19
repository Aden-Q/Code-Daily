def most_frequent(data):
    """
        determines the most frequently occurring string in the sequence.
    """
    # your code here
    s=''
    maxcount=0
    a=set(data)
    for i in a:
        if(data.count(i)>maxcount):
            maxcount=data.count(i)
            s=i
    return s

if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    print('Example:')
    print(most_frequent([
        'a', 'b', 'c', 
        'a', 'b',
        'a'
    ]))
    
    assert most_frequent([
        'a', 'b', 'c', 
        'a', 'b',
        'a'
    ]) == 'a'

    assert most_frequent(['a', 'a', 'bi', 'bi', 'bi']) == 'bi'
    print('Done')