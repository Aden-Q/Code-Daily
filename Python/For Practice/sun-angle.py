def sun_angle(time):
    hour = int(time[0] + time[1])
    minute = int(time[3] + time[4])
    t = hour + minute * 1.0 / 60
    if t < 6 or t > 18:
        return "I don't see the sun!"
    angle = (t - 6) * 1.0 / 12 * 180
    return float('%.2f' % angle)

if __name__ == '__main__':
    print("Example:")
    print(sun_angle("07:00"))

    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert sun_angle("07:00") == 15
    assert sun_angle("01:23") == "I don't see the sun!"
    print("Coding complete? Click 'Check' to earn cool rewards!")