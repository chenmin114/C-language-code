#include<stdio.h>

int main()
{
	int a,b,c,i;
	scanf("%d%d%d",&a,&b,&c);
	i = 1;
	while(i<=a)
	{
		printf("%d ",b);
		b = b + c;
		i=i+1;
	}
	return 0;
}	
		
	
	
