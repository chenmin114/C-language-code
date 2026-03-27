#include <stdio.h>
long long a[1000005]={0};
long long b[1000005]={0};
long long c[1000005]={0};
int main()
{
	int m,n,x=0,y=0,k=0;
	scanf("%d %d",&m,&n);
	for (int i=0;i<m;i++)
		scanf("%lld",&a[i]);
	for (int i=0;i<n;i++)
		scanf("%lld",&b[i]);
	while (x<m && y<n)
	{
		if (a[x]>=b[y])
		{
		    c[k] = b[y];
		    y += 1;
		    k++;
		}
		else
		{
		    c[k] = a[x]; 
			x +=1; 
			k++;
		}
	}
    while (x<m)
    {
	    c[k]=a[x];
		x++;
		k++;
    }
	while (y<n)
	{
	    c[k]=b[y];
		y++;
		k++;
	}						
	for (int i=0;i<m+n;i++)
	    printf("%lld ",c[i]);
	return 0;    
}
