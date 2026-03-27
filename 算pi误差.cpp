#include <stdio.h>
#include <math.h>
int a[100005]={0};;
int main() 
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) 
	{
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < T; i++) 
	{
        double x = 0.0,y = 0.0;
        for (int j = 0; j < a[i]; j++) 
		{
            x += pow(-1, j) / (2 * j + 1);
        }
        x *= 4;
        for (int j = 0; j < a[i]; j++) 
		{
            y += 1.0 / pow(2 * j + 1, 2);
        }
        y = sqrt(8 * y);
        printf("%.6lf\n", fabs(x - y));
    }
    return 0;
}
