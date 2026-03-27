#include <stdio.h>

int main() 
{
    int n,s;
    int a[200005];
    int b[200005];
    a[0] = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) 
	{
        scanf("%d", &b[i]);
        a[i] = b[i] + a[i - 1];
    }
    int m,k;
    scanf("%d", &m);
    for (int i = 0;i < m;i++)
    {
    	scanf("%d",&k);			
		if (a[n] < k)
		{
			printf("No Way!\n"); 
			break;
		}
		else 
		{
			for (int j=n;j>=1;j--)
			{
		        if (a[n] - a[j] == k)
			    {
				printf("%d\n",j+1);
				break;
			    }
			}	   
		}   
		
		
	}
	return 0;
}	
