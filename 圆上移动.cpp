#include<stdio.h>

int main()
{
	int n,m,x,a,sum=0;
	scanf("%d %d %d",&n,&m,&x);
	while(n--)
	{
		scanf("%d",&a);
		if(a>=0)
		{
			x=(x+a)%m;
		}
		else{
			x+=a;
			while(x<0){
				x+=m;
			}
		}
		if (x==0) sum++;
	}
	printf("%d",sum);
	return 0;
}
