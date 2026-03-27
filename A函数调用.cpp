#include <stdio.h>

int f1(int x) {
    return -~x++;
}
int f2(int x) {
    return ~-x++;
}
 
int main()
{
	int x,a,b;
	while ((scanf("%d",&x))!=EOF)
	{
		a=f1(x);
		b=f2(x);
		printf("%d %d\n",a,b);
	}
	return 0;
}
