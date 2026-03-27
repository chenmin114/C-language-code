#include <stdio.h>
int b[1000005]={0};
int main() 
{
	int a;
	scanf("%d",&a);
	for (int i=1;i<=a;i++) 
	{
		b[i] = (i & 1) ? b[i-1] + 1 : b[i >> 1];
	}	    
		    
		    
	for (int i = 0; i <= a; ++i) 
	{
		printf("%d ", b[i]);
	}
	return 0;
		
	
}
