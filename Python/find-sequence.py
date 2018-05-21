def checkio(matrix):
    #replace this for solution
    flag = False
    lm=len(matrix)
    for i in range(lm):
        for j in range(lm):
            h=matrix[i][j]
            if lm-j>=4:
                if h==matrix[i][j+1] and h==matrix[i][j+2] and h==matrix[i][j+3]:
                    flag=True
                    break
            if lm-i>=4:
                if h==matrix[i+1][j] and h==matrix[i+2][j] and h==matrix[i+3][j]:
                    flag=True
                    break
            if lm-i>=4 and lm-j>=4:
                if h==matrix[i+1][j+1] and h==matrix[i+2][j+2] and h==matrix[i+3][j+3]:
                    flag=True
                    break
            if i-3>=0 and j+3<lm:
                if h==matrix[i-1][j+1] and h==matrix[i-2][j+2] and h==matrix[i-3][j+3]:
                    flag=True
                    break
    return flag

if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert checkio([
        [1, 2, 1, 1],
        [1, 1, 4, 1],
        [1, 3, 1, 6],
        [1, 7, 2, 5]
    ]) == True, "Vertical"
    assert checkio([
        [7, 1, 4, 1],
        [1, 2, 5, 2],
        [3, 4, 1, 3],
        [1, 1, 8, 1]
    ]) == False, "Nothing here"
    assert checkio([
        [2, 1, 1, 6, 1],
        [1, 3, 2, 1, 1],
        [4, 1, 1, 3, 1],
        [5, 5, 5, 5, 5],
        [1, 1, 3, 1, 1]
    ]) == True, "Long Horizontal"
    assert checkio([
        [7, 1, 1, 8, 1, 1],
        [1, 1, 7, 3, 1, 5],
        [2, 3, 1, 2, 5, 1],
        [1, 1, 1, 5, 1, 4],
        [4, 6, 5, 1, 3, 1],
        [1, 1, 9, 1, 2, 1]
    ]) == True, "Diagonal"
