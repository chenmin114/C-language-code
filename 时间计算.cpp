#include <stdio.h>

// 判断是否为闰年
// 闰年规则：能被4整除但不能被100整除，或者能被400整除
int is_leap(int year) 
{
    if ((year%4==0 && year%100!=0) || (year%400==0)) 
	{
        return 1;
    }
    return 0;
}

// 获取某年某月的最大天数
int get_days_in_month(int year,int month) 
{
    int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (month==2) {
        if (is_leap(year)) 
		{
            return 29;
        }
    }
    return days[month];
}

int main() 
{
    int y, m, d, h, k;
    scanf("%d %d %d %d %d", &y, &m, &d, &h, &k);
    h+=k; 
    while (1) 
	{
        if (h>=24) 
		{
            h-=24;
            d++;
        } 
		else 
		{
            int max_days=get_days_in_month(y,m);
            if (d>max_days) 
			{
                d-=max_days;
                m++;
                if (m>12)
				{
                    m-=12;
                    y++;
                }
            } else {
                break;
            }
        }
    }
    printf("%d %d %d %d\n",y,m,d,h);
    return 0;
}
