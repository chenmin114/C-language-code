#include<stdio.h>

typedef long long ll;

const ll INF=4e18;

int T,n;
ll a[100005];

ll gcd(ll x,ll y)
{
    while(y>0)
    {
        long long z=y;
        y=x%y;
        x=z;
    }
    return x;
}

ll min(ll x,ll y)
{
    if(x>y) return y;
    return x;
}

ll max(ll x,ll y)
{
    if(x<y) return y;
    return x;
}

int main()
{
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++) scanf("%lld",&a[j]);
        int flag=1;
        for(int j=1;j<n;j++)
        {
            if(a[j]!=a[0]) 
			{
			    flag=0;
			    break;
			}    
        }
        if(flag)
        {
            printf("Infinite\n");
        }
        else
        {
            ll p,q,minn,maxn;
            p=a[0];
            q=0;
            minn=a[0];
            maxn=a[0];
            for(int j=1;j<n;j++)
            {
                p=gcd(p,a[j]);
                minn=min(minn,a[j]);
                maxn=max(maxn,a[j]);
            }
            for(int j=0;j<n;j++)
            {
				if (a[j]!=minn)
				{
					ll x=a[j]-minn;
					if (q==0)
					    q=x;
					else 
					    q=gcd(q,x);    
				}
            }
            printf("%lld %lld\n",p,q);
        }
    }
    return 0;
}
