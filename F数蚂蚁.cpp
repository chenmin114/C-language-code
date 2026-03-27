#include <stdio.h>

int main() 
{
	int a[10005]={0};
    int n,x;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
		scanf("%d",&x);
		a[x] += 1;
	}
	for (int i=0;i<=10000;i++)
	{
		if (a[i] != 0)
		    printf("%d : %d\n",i,a[i]);
	}
	return 0;
} 
