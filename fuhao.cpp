#include <stdio.h>
int a[2000005]={0}; 
int b[2000005]={0};
int main() 
{
    unsigned int a,b,c,d,e,f,g,h;
    int n;
		scanf("%d",&n);	
		int x = 0;
		for(int i=0;i<n;i++)
	    {
		    scanf("%u %u",&a,&b);
		    c = ~a;
		    d =a & b;
		    e = a|b;
		    f = a^b;
		    g = a << b;
		    h = a >> b;
		    printf("%u %u %u %u %u %u\n",c,d,e,f,g,h);
		    
	    }
	   return 0; 
}	
