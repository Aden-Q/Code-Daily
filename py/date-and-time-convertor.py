def date_time(time):
    #replace this for solution
    a=""
    a+=str(int(time[0:2]))
    a+=" "
    s=time[3:5]
    if s=="01":
        a+="January "
    elif s=="02":
        a+="February "
    elif s=="03":
        a+="March "
    elif s=="04":
        a+="April "
    elif s=="05":
        a+="May "
    elif s=="06":
        a+="June "
    elif s=="07":
        a+="July "
    elif s=="08":
        a+="August "
    elif s=="09":
        a+="September "
    elif s=="10":
        a+="October "
    elif s=="11":
        a+="November "
    elif s=="12":
        a+="December "
    a+=time[6:10]
    a+=" year "
    if time[11:13]=="01":
        a+="1 hour "
    else:
        a+=str(int(time[11:13]))
        a+=" hours "
    if time[14:16]=="01":
        a+="1 minute"
    else:
        a+=str(int(time[14:16]))
        a+=" minutes"
    return a

if __name__ == '__main__':
    print("Example:")
    print(date_time('01.01.2000 00:00'))

    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert date_time("01.01.2000 00:00") == "1 January 2000 year 0 hours 0 minutes", "Millenium"
    assert date_time("09.05.1945 06:30") == "9 May 1945 year 6 hours 30 minutes", "Victory"
    assert date_time("20.11.1990 03:55") == "20 November 1990 year 3 hours 55 minutes", "Somebody was born"
    print("Coding complete? Click 'Check' to earn cool rewards!")
