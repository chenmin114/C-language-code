#include <stdio.h>
#include <math.h>
#define eps 1e-9

int main()
{
    double a, b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    if (fabs(a)<eps&&fabs(b)<eps&&fabs(c)<eps)
	    printf("Infroots");
	else if (fabs(a)<eps&&fabs(b)<eps&&fabs(c)>eps)
	    printf("No Root");
	else if (fabs(a)<eps&&fabs(b)>eps)
	    printf("Just one root: %.2f",-c/b);
	else
	{
	    double k=b*b-4*a*c;
	    if (fabs(k)<=eps)
	        printf("The same two roots:%.2f",-b/(2*a));
	    else if(k<-eps)
	        printf("No Root");
	    else if (a>eps)
	        printf("%.2f %.2f",(-b+sqrt(k))/2*a,(-b-sqrt(k))/(2*a));
	    else
	        printf("%.2f %.2f",(-b-sqrt(k))/2*a,(b+sqrt(k))/(2 * a));
	}
	return 0;
}	
