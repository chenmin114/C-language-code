#include <stdio.h>
#include <math.h>
#define M 1e-8

inline int read() 
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') 
	{
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') 
	{
        x = x * 10 + (ch - '0'); 
        ch = getchar();
    }
    return x * f;
}

int main() 
{
    int T = read();
    while (T--) 
	{
        double a = read(), b = read(), c = read(), x1 = read(), y1 = read(),x2 = read(), y2 = read();
        if (a != 0) 
		{ 
            double dx = x2 - x1;
            if (fabs(dx) < M) 
			{ 
                double y_quad = a * x1 * x1 + b * x1 + c;
                if (fabs(y_quad - y1) < M) 
				{
                    printf("-1\n");
                } 
				else 
				{
                    printf("0\n");
                }
            } 
			else 
			{ 
                double k = (y2 - y1) / dx;
                double b_line = y1 - k * x1;
                double A = a;
                double B = b - k;
                double C = c - b_line;
                double D = B * B - 4 * A * C; 
                double denom = 2 * A; 

                if (D < -M) 
				{
                    printf("0\n");
                } 
				else if (fabs(D) < M) 
				{ 
                    double x = -B / denom;
                    double y = a * x * x + b * x + c; 
                    printf("1 %.2f %.2f\n", x, y);
                } 
				else 
				{ 
                    double sqrtD = sqrt(D);
                    double x_sol1 = (-B - sqrtD) / denom;
                    double x_sol2 = (-B + sqrtD) / denom;
                    double y_sol1 = a * x_sol1 * x_sol1 + b * x_sol1 + c;
                    double y_sol2 = a * x_sol2 * x_sol2 + b * x_sol2 + c;
                    if (x_sol1 > x_sol2) 
					{
                        double tmp = x_sol1; x_sol1 = x_sol2; x_sol2 = tmp;
                        tmp = y_sol1; y_sol1 = y_sol2; y_sol2 = tmp;
                    }
                    printf("2 %.2f %.2f %.2f %.2f\n", x_sol1, y_sol1, x_sol2, y_sol2);
                }
            }
        } 
		else 
		{ 
            double dx = x2 - x1;
            if (fabs(dx) < M) 
			{ 
                double x = x1;
                double y = b * x + c; 
                printf("1 %.2f %.2f\n", x, y);
            } 
			else 
			{ 
                double k = (y2 - y1) / dx;
                double b_line = y1 - k * x1;
                double diff_bk = b - k; 

                if (fabs(diff_bk) < M) 
				{ 
                    if (fabs(c - b_line) < M) 
					{
                        printf("-1\n");
                    } 
					else 
					{
                        printf("0\n");
                    }
                } 
				else 
				{ 
                    double x = (b_line - c) / diff_bk;
                    double y = b * x + c; 
                    printf("1 %.2f %.2f\n", x, y);
                }
            }
        }
    }
    return 0;
}
