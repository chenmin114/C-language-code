#include <stdio.h>
#include <math.h>
#define eps 1e-9

int main()
{
    double a, b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    if (fabs(a) <= eps)
    {
		if (fabs(a - b) <= eps)
		{
			if (fabs(b - c) <= eps)
			    printf("Infroots\n");
			else
			    printf("No Root\n");		    
		}
		else
		{
			double x0 = -c / b;
			printf("Just one root: %.2f\n",x0);
		}
	}
	else
	{
		double t = b * b - 4 * a * c;
		if (fabs(t) < eps)
		    printf("The same two roots: %.2f\n",-b/(2*a));
		else if (t > 0)
		{
			double x1,x2;
			x1 = (-b + sqrt(t)) / (2 * a);
			x2 = (-b - sqrt(t)) / (2 * a);
			if (x1 < x2)
			{
				double x = x1;
				x1 = x2;
				x2 = x;
			}
			printf("%.2f %.2f\n",x1,x2);
		} 
		else
		    printf("No Root");   

			
	
	}

    

    return 0;
}
