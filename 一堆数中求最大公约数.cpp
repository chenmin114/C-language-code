#include <stdio.h>
long long a[100005];

long long gcd(long long a,long long b) 
{
    while (b!=0) 
	{
        long long temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int main() 
{
    int n,q;
    scanf("%d %d",&n,&q);
    for (int i=0;i<n;i++) 
	{
        scanf("%lld",&a[i]);
    }
    // 根据公式 gcd(a1+i, a2+i, ...) = gcd(a1+i, a2-a1, a3-a1, ...)
    long long gd=0;
    for (int i=1;i<n;i++) 
	{
        long long d=a[i]-a[0];
        if (d<0) d=-d;
        gd=gcd(gd,d);
    }
    // 2. 处理查询
    for (int i=1;i<=q;i++) 
	{

        long long x=a[0]+i;
        if (n==1) 
		{
            // 如果只有一个数，GCD 就是它本身
            printf("%lld\n",x);
        } 
		else 
		{
            printf("%lld\n", gcd(x, gd));
        }
    }
    return 0;
}
