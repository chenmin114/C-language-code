#include <stdio.h>
long long t[200005], s[500005];
int main()
{
    long long n,i,sum=0,mus=0,p,m;
    
	scanf("%lld",&n);
    getchar();
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &t[i]);
        sum+=t[i];
    }
    for(i=n-1;i>-1;i--){
         mus+=t[i];
         s[mus]=i;
    }
    scanf("%lld", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%lld", p);
        printf("%lld\n",s[p]+1);
    }
    return 0;
}