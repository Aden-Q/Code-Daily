#include <stdio.h>
#include <string.h>
#define MAXLENGTH 60

char *for_day(char n);
char *for_hour(char n);
char *for_minute(int n);

char day[4];
char hour[3];
char minute[3];

int main(void) {
	char s[4][MAXLENGTH];
	char _day[4];
	char _hour[3];
	char _minute[3];
	int i;
	int min;
	int flag;
	scanf("%s%s%s%s", s[0], s[1], s[2], s[3]);
	min = strlen(s[0]);
	if (strlen(s[1]) < min)
		min = strlen(s[1]);
	else;
	for (i = 0; i < min; i++) {
		if (s[0][i] >= 'A'&&s[0][i] <= 'G') {
			if (s[0][i] == s[1][i])
				break;
			else;
		}
		else;
	}
	flag = i + 1;
	strcpy(_day, for_day(s[0][i]));

	for (i = flag; i < min; i++) {
		if ((s[0][i] >= '0'&&s[0][i] <= '9') || (s[0][i] >= 'A'&&s[0][i] <= 'N')) {
			if (s[0][i] == s[1][i])
				break;
		}
		else;
	}
	strcpy(_hour, for_hour(s[0][i]));

	min = strlen(s[2]);
	if (strlen(s[3]) < min)
		min = strlen(s[3]);
	else;
	for (i = 0; i < min; i++) {
		if ((s[2][i] >= 'A'&&s[2][i] <= 'Z') || (s[2][i] >= 'a'&&s[2][i] <= 'z')) {
			if (s[2][i] == s[3][i])
				break;
			else;
		}
		else;
	}
	strcpy(_minute, for_minute(i));
	printf("%s %s:%s", _day, _hour, _minute);
	return 0;
}

char *for_day(char n) {
	int flag;
	flag = n - 'A';
	if (flag == 0)
		strcpy(day, "MON");
	else if (flag == 1)
		strcpy(day, "TUE");
	else if (flag == 2)
		strcpy(day, "WED");
	else if (flag == 3)
		strcpy(day, "THU");
	else if (flag == 4)
		strcpy(day, "FRI");
	else if (flag == 5)
		strcpy(day, "SAT");
	else if (flag == 6)
		strcpy(day, "SUN");
	else;
	return day;
}

char *for_hour(char n) {
	if (n == '0')
		strcpy(hour, "00");
	else if (n == '1')
		strcpy(hour, "01");
	else if (n == '2')
		strcpy(hour, "02");
	else if (n == '3')
		strcpy(hour, "03");
	else if (n == '4')
		strcpy(hour, "04");
	else if (n == '5')
		strcpy(hour, "05");
	else if (n == '6')
		strcpy(hour, "06");
	else if (n == '7')
		strcpy(hour, "07");
	else if (n == '8')
		strcpy(hour, "08");
	else if (n == '9')
		strcpy(hour, "09");
	else if (n == 'A')
		strcpy(hour, "10");
	else if (n == 'B')
		strcpy(hour, "11");
	else if (n == 'C')
		strcpy(hour, "12");
	else if (n == 'D')
		strcpy(hour, "13");
	else if (n == 'E')
		strcpy(hour, "14");
	else if (n == 'F')
		strcpy(hour, "15");
	else if (n == 'G')
		strcpy(hour, "16");
	else if (n == 'H')
		strcpy(hour, "17");
	else if (n == 'I')
		strcpy(hour, "18");
	else if (n == 'J')
		strcpy(hour, "19");
	else if (n == 'K')
		strcpy(hour, "20");
	else if (n == 'L')
		strcpy(hour, "21");
	else if (n == 'M')
		strcpy(hour, "22");
	else if (n == 'N')
		strcpy(hour, "23");
	else;
	return hour;
}

char *for_minute(int n) {
	if (n == 0)
		strcpy(minute, "00");
	else if (n == 1)
		strcpy(minute, "01");
	else if (n == 2)
		strcpy(minute, "02");
	else if (n == 3)
		strcpy(minute, "03");
	else if (n == 4)
		strcpy(minute, "04");
	else if (n == 5)
		strcpy(minute, "05");
	else if (n == 6)
		strcpy(minute, "06");
	else if (n == 7)
		strcpy(minute, "07");
	else if (n == 8)
		strcpy(minute, "08");
	else if (n == 9)
		strcpy(minute, "09");
	else if (n == 10)
		strcpy(minute, "10");
	else if (n == 11)
		strcpy(minute, "11");
	else if (n == 12)
		strcpy(minute, "12");
	else if (n == 13)
		strcpy(minute, "13");
	else if (n == 14)
		strcpy(minute, "14");
	else if (n == 15)
		strcpy(minute, "15");
	else if (n == 16)
		strcpy(minute, "16");
	else if (n == 17)
		strcpy(minute, "17");
	else if (n == 18)
		strcpy(minute, "18");
	else if (n == 19)
		strcpy(minute, "19");
	else if (n == 20)
		strcpy(minute, "20");
	else if (n == 21)
		strcpy(minute, "21");
	else if (n == 22)
		strcpy(minute, "22");
	else if (n == 23)
		strcpy(minute, "23");
	else if (n == 24)
		strcpy(minute, "24");
	else if (n == 25)
		strcpy(minute, "25");
	else if (n == 26)
		strcpy(minute, "26");
	else if (n == 27)
		strcpy(minute, "27");
	else if (n == 28)
		strcpy(minute, "28");
	else if (n == 29)
		strcpy(minute, "29");
	else if (n == 30)
		strcpy(minute, "30");
	else if (n == 31)
		strcpy(minute, "31");
	else if (n == 32)
		strcpy(minute, "32");
	else if (n == 33)
		strcpy(minute, "33");
	else if (n == 34)
		strcpy(minute, "34");
	else if (n == 35)
		strcpy(minute, "35");
	else if (n == 36)
		strcpy(minute, "36");
	else if (n == 37)
		strcpy(minute, "37");
	else if (n == 38)
		strcpy(minute, "38");
	else if (n == 39)
		strcpy(minute, "39");
	else if (n == 40)
		strcpy(minute, "40");
	else if (n == 41)
		strcpy(minute, "41");
	else if (n == 42)
		strcpy(minute, "42");
	else if (n == 43)
		strcpy(minute, "43");
	else if (n == 44)
		strcpy(minute, "44");
	else if (n == 45)
		strcpy(minute, "45");
	else if (n == 46)
		strcpy(minute, "46");
	else if (n == 47)
		strcpy(minute, "47");
	else if (n == 48)
		strcpy(minute, "48");
	else if (n == 49)
		strcpy(minute, "49");
	else if (n == 50)
		strcpy(minute, "50");
	else if (n == 51)
		strcpy(minute, "51");
	else if (n == 52)
		strcpy(minute, "52");
	else if (n == 53)
		strcpy(minute, "53");
	else if (n == 54)
		strcpy(minute, "54");
	else if (n == 55)
		strcpy(minute, "55");
	else if (n == 56)
		strcpy(minute, "56");
	else if (n == 57)
		strcpy(minute, "57");
	else if (n == 58)
		strcpy(minute, "58");
	else if (n == 59)
		strcpy(minute, "59");
	else;
	return minute;
}