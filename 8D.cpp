#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char s[105];

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++)
	{
		scanf("%s",&s);
		if (s[2]=='B')
		{
			int n;
			double p;
			sscanf(s,"%*[^(](%d,%lf)",&n,&p);
			double e=n*p;
			double d=n*p*(1-p);
			printf("E(%c)=%.4lf,D(%c)=%.4lf\n",s[0],e,s[0],d);
		}
		else if (s[2]=='P') 
		{
			double p;
			sscanf(s,"%*[^(](%lf)",&p);
			double e=p;
			double d=p;
			printf("E(%c)=%.4lf,D(%c)=%.4lf\n",s[0],e,s[0],d); 
		}
		else if (s[2]=='G')
		{
			double p;
			sscanf(s,"%*[^(](%lf)",&p);
			double e=1.0/p;
			double d=(1-p)/pow(p,2);
			printf("E(%c)=%.4lf,D(%c)=%.4lf\n",s[0],e,s[0],d);
		}
		else if (s[2]=='U')
		{

			double n,p;
			sscanf(s,"%*[^(](%lf,%lf)",&n,&p);
			double e=(n+p)/2.0;
			double d=pow(p-n,2)/12.0;
			printf("E(%c)=%.4lf,D(%c)=%.4lf\n",s[0],e,s[0],d);
		}
		else if (s[2]=='N')
		{
			double n,p;
			sscanf(s,"%*[^(](%lf,%lf)",&n,&p);
			double e=n;
			double d=p;
			printf("E(%c)=%.4lf,D(%c)=%.4lf\n",s[0],e,s[0],d);
		}
	}
	return 0;
}
