#include<stdio.h>

int main()
{
	int n,m,s,t;
	scanf("%d%d",&n,&m);
	s = (m - 8 * n) / 2;
	t = (10 * n - m) / 2;
	if (s>=0 and t>=0)
	    printf("%d",s);
	else
	    printf("ERROR");
	return 0;
}	    
	    
	
	
