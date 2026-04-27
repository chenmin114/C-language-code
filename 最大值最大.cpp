#include <stdio.h>
int c[100005];

int main() 
{
    int n, m;
    scanf("%d %d",&n,&m);
    int max=0;
    for (int i=0;i<n;i++) 
	{
        scanf("%d",&c[i]);
        if (c[i]>max) max=c[i];
    }
    long long sumall=0;
    long long sumpos=0;
    for (int j=0;j<m;j++) 
	{
        int a;
        scanf("%d",&a);
        sumall+=a;
        if (a>0) sumpos+=a;
    }
    
    if (n==1) 
	{
        printf("%lld\n",c[0]+sumall);
    } 
	else printf("%lld\n",max+sumpos);
    return 0;
}
