def to_encrypt(text, delta):
    rstr = "abcdefghijklmnopqrstuvwxyz"
    n_text = ""
    for i in range(len(text)):
        if text[i]==" ":
            n_text += " "
        else:
            index = rstr.find(text[i]) + delta
            if index < 0:
                index += 26
            elif index > 25:
                index -= 26
            n_text += rstr[index]
        
    return n_text

if __name__ == '__main__':
    print("Example:")
    print(to_encrypt('abc', 10))

    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert to_encrypt("a b c", 3) == "d e f"
    assert to_encrypt("a b c", -3) == "x y z"
    assert to_encrypt("simple text", 16) == "iycfbu junj"
    assert to_encrypt("important text", 10) == "swzybdkxd dohd"
    assert to_encrypt("state secret", -13) == "fgngr frperg"
    print("Coding complete? Click 'Check' to earn cool rewards!")