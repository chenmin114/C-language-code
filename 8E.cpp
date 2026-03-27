#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI acos(-1)
double x[2000005],y[2000005];

double f(double x1, double y1, double x2, double y2) 
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int main() 
{
    int T;
    scanf("%d", &T);   
    while (T--) 
	{
        int n, r;
        scanf("%d %d", &n, &r);        
        for (int i = 0; i < n; i++) 
		{
            scanf("%lf %lf", &x[i], &y[i]);
        }
        double sum =2.0*PI*r;
        for (int i = 0; i < n; i++) 
		{
            int next = (i + 1) % n;
            sum += f(x[i], y[i], x[next], y[next]);
        }        

        printf("%.15f\n",sum);
    }
    return 0;
}
