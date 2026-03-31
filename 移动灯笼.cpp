#include<stdio.h>

int main()
{
	int t,x,y,z;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&x,&y,&z);
		int a=y-x-1,b=z-y-1;
		if (a==0 && b==0)
		{
			printf("0\n");
		}
		else{
			if (a>=b){
				printf("%d\n",a);
			}
			else printf("%d\n",b);
		}
	}
	return 0;
}
