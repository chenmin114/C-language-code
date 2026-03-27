#include <stdio.h>
int month[14]={0,31,28,31,30,31,30,31,31,30,31,30,31,0};

int check(int y)
{
	if ((y%4==0 && y%100!=0) || y%400==0)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int t;
	while (scanf("%d",&t)!=EOF)
	{
		int y=t/10000;
		int m=t/100%100;
		int d=t%100;
		int re=99;
		if (check(y))
		{
		    month[13]=30;
		    month[2]=29;
		    re+=(d-1);
		    while (re>month[m])
		    {
				re-=month[m];
				m++;
				if (m==14)
				{
				    m-=13;
				    y++;
				    if (check(y)) month[2]=29;
				    else month[2]=28;
				}
			}
			d=re+1;
			printf("%d\n",10000*y+100*m+d);
			month[2]=28;
		}
		else{
		    re+=(d-1);
		    while (re>month[m])
		    {
				re-=month[m];
				m++;
				if (m==13)
				{
				    m-=12;
				    y++;
				    if (check(y)) month[2]=29;
				    else month[2]=28;
				}
			}
			d=re+1;
			printf("%d\n",10000*y+100*m+d);	
			month[2]=28;		
		}		    
	}
	return 0;
}
