#include <stdio.h>
#include <math.h>

int main()
{
	double x1,y1,x2,y2,x3,y3;
	scanf("%lf %lf",&x1,&y1);
	scanf("%lf %lf",&x2,&y2);
	scanf("%lf %lf",&x3,&y3);
	double c1 = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	double c2 = sqrt(pow(x3-x1,2)+pow(y3-y1,2));
	double c3 = sqrt(pow(x3-x2,2)+pow(y3-y2,2));
	double C = c1+c2 +c3;
	printf("%.2lf",C);
	return 0;
	
}
