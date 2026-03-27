#include <stdio.h>
#include <stdlib.h>
long long x[100005]={0};
long long y[100005]={0};
int main() 
{
    int n;
    scanf("%d",&n);
    long long a=0,b=0;
    for (int i=0;i<n;i++)
        scanf("\n(%lld,%lld)",&x[i],&y[i]);
    for (int i=0;i<n;i++)
	{
		int t=(i+1)%n;
		a +=x[i]*y[t];
		b +=x[t]*y[i]; 
	}
	if (llabs(a-b) % 2==1)    
        printf("%lld.5\n",llabs(a-b)/2);
    else 
	    printf("%lld.0\n",llabs(a-b)/2);   
    return 0;
}
