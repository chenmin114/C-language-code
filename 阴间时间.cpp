#include <stdio.h>

int runnian(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Month(int year, int month) 
{
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && runnian(year)) 
	{
        return 29;
    }
    return days[month];
}
int main() 
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
	{
        int year, month, day, hour, minute;
        scanf("%d.%d.%d %d:%d", &year, &month, &day, &hour, &minute);
        if (minute >= 60) 
		{
            hour += minute / 60;
            minute %= 60;
        }
        if (hour >= 24) 
		{
            day += hour / 24;
            hour %= 24;
        }
        while (1) 
		{
            int days = Month(year, month);
            if (day <= days) 
			{
                break;
            }
            day -= days;
            month++;
            if (month > 12) 
			{
                month -= 12;
                year++;
            }
        }
        if (year >= 10000) 
		{
            printf("%d.%02d.%02d %02d:%02d\n", year, month, day, hour, minute);
        } 
		else 
		{
            printf("%04d.%02d.%02d %02d:%02d\n", year, month, day, hour, minute);
        }
    }

    return 0;
}
