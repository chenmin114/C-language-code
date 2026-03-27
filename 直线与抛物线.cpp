#include <stdio.h>
#include <math.h>

int main() 
{
    int T;
    scanf("%d", &T);
    for (int i=0;i<T;i++) 
	{
        int a, b, c;
        int x1, y1, x2, y2;
        scanf("%d %d %d", &a, &b, &c);
        scanf("%d %d", &x1, &y1);
        scanf("%d %d", &x2, &y2);
        double dx = x2 - x1;
        double dy = y2 - y1;
        double k = dy / dx;          
        double bl = y1 - k * x1;   
        double A = a;
        double B = b - k;
        double C = c - bl;
        if (fabs(A) < 1e-8) 
		{  
            if (fabs(B) > 1e-8) 
			{  
                double x = -C / B;
                double y = k * x + bl;
                printf("1 (%.2f,%.2f)\n", x, y);
            } 
			else 
			{  
                if (fabs(C) < 1e-8) 
				{
                    printf("-1\n");  
                } else {
                    printf("0\n");   
                }
            }
        } 
		else 
		{  
            double delta = B * B - 4 * A * C;
            if (delta < -1e-8) 
			{  
                printf("0\n");
            } 
			else if (delta > 1e-8) 
			{  
                double sqrtdelta = sqrt(delta);
                double x1root = (-B - sqrtdelta) / (2 * A);
                double x2root = (-B + sqrtdelta) / (2 * A);
                double y1root = k * x1root + bl;
                double y2root = k * x2root + bl;
                if (x1root > x2root) 
				{
                    double sx = x1root, sy = y1root;
                    x1root = x2root;
                    y1root = y2root;
                    x2root = sx;
                    y2root = sy;
                }
                printf("2 (%.2f,%.2f) (%.2f,%.2f)\n", x1root, y1root, x2root, y2root);
            } 
			else 
			{  
                double x = -B / (2 * A);
                double y = k * x + bl;
                printf("1 (%.2f,%.2f)\n", x, y);
            }
        }
    }
    return 0;
}
