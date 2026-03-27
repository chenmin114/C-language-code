#include <stdio.h>
#include <math.h>
int main() 
{
	int h,f,t,y,x,s;
	scanf("%d %d %d",&h,&f,&t);
	if (h <= 5)
	{
		int z=f*pow(2,2+h);
		if (z>2000)
		    y=2000;
		else
		    y=z;    
	}
	else if (h<=7)
	    y=3000;
	else if (h<=10)
		y=4000;
	else if (h<=12)
		y=6000;
	else 
		y=8000;		
	x = 4*y;
	s = x + t;
	printf("%d",s);			    
    return 0;
}
