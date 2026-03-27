#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	double a,b;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%lf %lf",&a,&b);
		double t=pow(a,2)+pow(b,2);
		if (a==b)
		{
			double ans=sqrt(t);
			printf("%.3lf\n",ans);
		}
		else 
		{
			double ans1=sqrt(t);
			double t2=fabs(pow(a,2)-pow(b,2));
			double ans2=sqrt(t2);
			if (ans1>ans2)
			{
				double temp=ans1;
				ans1=ans2;
				ans2=temp;
			}
			printf("%.3lf %.3lf\n",ans1,ans2);		
		}
	}
	return 0;
}
