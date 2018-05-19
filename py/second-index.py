def second_index(text: str, symbol: str):
    """
        returns the second index of a symbol in a given text
    """
    # your code here
    i = text.find(symbol)
    if i==-1:
        return None
    else:
        s = text[i+1:]
        k = s.find(symbol)
        if k == -1:
            return None
        else:
            return k+1+i


if __name__ == '__main__':
    print('Example:')
    print(second_index("sims", "s"))

    # These "asserts" are used for self-checking and not for an auto-testing
    assert second_index("sims", "s") == 3, "First"
    assert second_index("find the river", "e") == 12, "Second"
    assert second_index("hi", " ") is None, "Third"
    assert second_index("hi mayor", " ") is None, "Fourth"
    assert second_index("hi mr Mayor", " ") == 5, "Fifth"
    print('You are awesome! All tests are done! Go Check it!')
