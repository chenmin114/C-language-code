#include <stdio.h>
int p[500005]={0};

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	int left=0,right=n-1,lmax=0,rmax=0;
	long long sum=0;
	while (left <= right)
	{
		if (lmax < rmax)
		{
			if (p[left] < lmax)
			{
				sum +=lmax-p[left];
			}
			else
			    lmax = p[left];
			left++;
		}
		else
		{
			if (p[right] < rmax)
			    sum += rmax-p[right];
			else
			    rmax = p[right];
			right--;	    
		}
	}  
	printf("%lld",sum);
	return 0;
}
