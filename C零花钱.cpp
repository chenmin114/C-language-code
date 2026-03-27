#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int money=0,nowmoney=1,passday=0;
	while (passday<n)
	{
		if (nowmoney<15) 
		{
		int day=nowmoney;
		if (day > n-passday)
		    day = n-passday;
		passday += day;
		money += nowmoney * day;
		nowmoney++;
		}
		else
		{
			money += nowmoney * (n - passday);
			passday = n;
		}    
	}
	printf("%d",money);
	return 0;
}
