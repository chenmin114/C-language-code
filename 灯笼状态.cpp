#include <stdio.h>
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int lantern[1005] = {0};
	for (int i = 0;i < m;i++)
	{
		int a,x1,x2,x3;
		scanf("%d",&a);
		x1 = (a - 2 + n) % n; 
		x2 = (a - 1 + n) % n;
		x3 = (a + n) % n;
		lantern[x1] = 1 - lantern[x1];
		lantern[x2] = 1 - lantern[x2];
		lantern[x3] = 1 - lantern[x3];
	}
	for (int j = 0;j < n; j++)
	{
		printf("%d ",lantern[j]);
	}
	return 0;
}	
