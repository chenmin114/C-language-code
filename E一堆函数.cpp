#include <stdio.h>
#include <math.h>
unsigned int f(unsigned int x)
{
	return (x+2)*x+9;	
}
unsigned int g(unsigned int x)
{
	return f(x)+f(2*f(x+3))+3*x;
}
unsigned int h(unsigned int x,unsigned int y)
{
	return g(f(x)+y)+f(3*g(4*x+y))+g(f(f(x-y)));
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) 
	{
	    unsigned int x, y;
	    scanf("%u %u", &x, &y);
	    
	    printf("%u\n",h(x,y));    
	} 
	return 0;
}
