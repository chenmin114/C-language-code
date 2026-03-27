#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long l, r;
} I;

int cmp(const void *p, const void *q) 
{
    if(*(long long *)p > *(long long *)q) 
        return 1;
    else if(*(long long *)p < * (long long *)q) return -1;
    else return 0;
}

int main() 
{
    long long L;
    int n;
    scanf("%lld %d", &L, &n);
    I *wa=(I *)malloc(n * sizeof(I));
    for (int i = 0; i < n; i++) 
	{
        scanf("%lld %lld", &wa[i].l, &wa[i].r);
    }
    if (L==0)
    {
		printf("YE5\n");
		printf("0\n");
		free(wa);
		return 0;
	}
	if (n==0)
	{
		printf("NO\n");
		printf("%lld",L);
		free(wa);
		return 0;
	}
    qsort(wa, n, sizeof(I), cmp);
    long long c=0;
    int count=0,i=0,you=0;
    while (c<L) 
	{
        long long maxr=c;
        int flag=0;
        while (i<n && wa[i].l<=c) 
		{
            if (wa[i].r > maxr) 
			{
                maxr=wa[i].r;
                flag=1;
            }
            i++;
        }

        if (!flag) 
		{
           break;
        } 
        c=maxr;
        count++;
        you=1;
        if (maxr==c && maxr<L)
        {
			if (i>=n || wa[i].l>c+1)
			    break;
		}
    }
    if (c>=L && you) 
	{
        printf("YE5\n");
        printf("%d\n",count);
    } 
	else 
	{
        printf("NO\n");
        printf("%lld\n",L-c);
    }
    free(wa);
    return 0;
}
