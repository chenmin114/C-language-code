#include <stdio.h>

int main() 
{
	int n,q;
	scanf("%d",&n);
	long long length[114514] = {0};
	for (int i = 2; i <= n; ++i) 
	{
		int d;
		scanf("%d",&d);
		length[i] = length[i-1] + d + 190;
	}
	scanf("%d",&q);
	while (q--)
	{
		int s, t;
		scanf("%d %d",&s,&t);
		long long distance = length[t] - length[s];
		printf("%lld\n",distance);
	}
	return 0;
}	
