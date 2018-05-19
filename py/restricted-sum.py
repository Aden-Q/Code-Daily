val=0
def checkio(data):
    global val
    val = 0
    checks(data, len(data)-1)
    return val


def checks(data, j):
    global val
    if(j>=0):
        val+=data[j]
    else:
        return
    checks(data, j-1)