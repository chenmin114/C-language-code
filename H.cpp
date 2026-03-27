#include<stdio.h>

int main()
{
	int a,b,c,d;
	scanf("%d%d%d", &a, &b,&c);
	
	d = a;
	    if(b > d)
	        d = b;
	    if(c > d)
		        d = c;
	    while (d % a != 0 || d % b != 0 || d % c != 0)
	    {
	        d = d + 1; 
	    }
	    printf("%d", d);
	
	    return 0;
	}
