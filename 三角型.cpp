#include <stdio.h>
#include <math.h>

int main() 
{
	double x1,y1,x2, y2,x3,y3,s1,s2,s3,s;
	scanf("%lf %lf",&x1,&y1);
	scanf("%lf %lf",&x2,&y2);
	scanf("%lf %lf",&x3,&y3);
	s1 = sqrt((x1 - x2) * (x1 - x2 ) + (y1 - y2) * (y1 - y2));
	s2 = sqrt((x2 - x3) * (x2 - x3 ) + (y2 - y3) * (y2 - y3));
	s3 = sqrt((x3 - x1) * (x3 - x1 ) + (y3 - y1) * (y3 - y1));
	s = s1 + s2 + s3;
	printf("%.2f\n",s);
	return 0;
}	
