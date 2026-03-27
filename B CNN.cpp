#include <stdio.h>
int a[45][45] = {0};
int b[45][45] = {0};
int c[45][45] = {0};

int main() 
{
    int n, m;
    scanf("%d %d", &n, &m);
    int kernel[40][40] = {0};
    for (int i=0;i<n;i++) 
	{
        for (int j=0;j<n;j++) 
		{
            scanf("%d", &a[i][j]);
        }
    }
    for (int i=0; i<m;i++) 
	{
        for (int j=0; j < m;j++) 
		{
            scanf("%d", &b[i][j]);
        }
    }
    int t = m - n + 1;
    for (int i = 0; i <t; ++i) 
	{
        for (int j=0;j<t;j++) 
		{
            int sum = 0;
            for (int p=0;p<n; p++) 
			{
                for (int q=0;q<n;q++) 
				{
                    sum += a[p][q] * b[i+p][j+q];
                }
            }
            c[i][j] = sum;
        }
    }
    for (int i = 0;i<t;i++) 
	{
        for (int j=0; j<t;j++) 
		{
            printf("%d",c[i][j]);
            if (j<t - 1) 
			{
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
