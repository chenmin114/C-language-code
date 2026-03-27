#include <stdio.h>

int main() 
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
		int x;
		scanf("%d",&x);
		if (x % 6 == 0)
		{
			printf("Tom wins\n");	
		}
		else
		{
			printf("Jerry wins\n");
		}
	}
	return 0;
}	





