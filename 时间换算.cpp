#include <stdio.h>

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int runnian(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDays(int year, int month) 
{
    return (month == 2 && runnian(year)) ? 29 : days[month];
}

int main() 
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
	{
        int year, month, day, hour, minute;
        scanf("%d.%d.%d %d:%d", &year, &month, &day, &hour, &minute);
        hour += minute / 60;  
        minute %= 60;      
        day += hour / 24;   
        hour %= 24;        

        if (day > 0) 
		{  
            int month1 = year * 12 + month;
            while (1) 
			{
                int year1 = month1 / 12;    
                int month2 = month1 % 12;    
                if (month2 == 0) 
				{                 
                    year1--;
                    month2 = 12;
                }
                int days = getDays(year1, month2);
                if (day <= days) 
				{
                    break;  
                }
                day -= days;          
                month1++;     
            }
            year = month1 / 12;
            month = month1 % 12;
            if (month == 0) 
			{  
                year--;
                month = 12;
            }
        }
        if (year >= 10000) 
		{
            printf("%05d.%02d.%02d %02d:%02d\n", year, month,day, hour, minute);
        } 
		else 
		{
            printf("%04d.%02d.%02d %02d:%02d\n", year, month, day, hour, minute);
        }
    }

    return 0;
}
