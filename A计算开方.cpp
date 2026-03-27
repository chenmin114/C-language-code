#include <stdio.h>
#include <math.h>

int main() 
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
	{
        int x, y;
        scanf("%d %d", &x, &y);
        double r = pow(x, 1.0 / y);
        printf("%.5f\n", r);
    }
    return 0;
}
