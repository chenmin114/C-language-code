#include <stdio.h>
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int T,y,m,d,sum;
	scanf("%d",&T);
	for (int a=0;a<T;a++)
	{
	    scanf("%d %d %d",&y,&m,&d);
	    sum=d;
	    for (int i=0;i<m;i++)
	    {
			sum += month[i];
			if (2==i && ((y %4==0 && y %100 !=0) ||(y % 400 ==0)))
			    sum +=1;
	    }
		printf("%d\n",sum);    
			  
		
	}
	return 0;
}
