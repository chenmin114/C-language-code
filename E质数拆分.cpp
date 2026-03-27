#include <stdio.h>
#include <math.h>
int a[1000005];

void s() 
{
    for (int i=2;i<=1000005;i++) 
	{
        if (a[i] == 0) 
		{ 
            a[i] = i;
            if ((long long)i*i<=1000005) 
			{
                for (int j = i*i;j <=1000005; j += i) 
				{
                    if (a[j] == 0) 
					{
                        a[j] = i;
                    }
                }
            }
        }
    }
} 

int zhishu(int n)
{
	for(int i=2;i<sqrt(n);i++)
	{
	    if(n%i==0)
	    {
	        return 0;
	    }
	}
    return 1;
}

void split(int x, int *p, int *q) 
{
    int t=(int)sqrt(x);
    for (int i =t;i>=2;i--) 
	{
        if (x % i == 0) 
		{
            *p = i;
            *q = x / i;
            return;
        }
    }
    *p=1;
    *q=x;
}

void S(int x, int one) {
    if (zhishu(x)) {
        if (!one) {
            printf("*");
        }
        printf("%d", x);
        return;
    }    
    int p, q;
    split(x, &p, &q);    
    S(p, one);
    S(q, 0);
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int x;
		scanf("%d",&x);			
	    if (x==1)
	    {
		    printf("1\n");
		    continue;
	    }
	    S(x,1);
	    printf("\n");
	}
	return 0;    
}
