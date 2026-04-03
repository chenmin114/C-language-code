#include <stdio.h>
#include <stdlib.h>
long long count[1001]={0};
#define MOD 1000000007 

int main()
{
    int n;
    scanf("%d",&n);
    long long sum=0;
    for (int i=1;i<=n;i++) 
    {
        int x;
        scanf("%d", &x);
        count[x]++;
    }
    for (int i=1;i<=1000;i++) 
    {
        for (int j=1;j<=1000;j++) 
        {
            if (i==j) 
            {
                sum+=count[i]*(count[i]-1)*(count[i]-2)*(count[i]-3);//A(m,4)
            }
            else sum+=(count[i])*(count[i]-1)*(count[j]-1)*count[j];//A(m,2)*A(n,2)
            sum%=MOD;
        }
    }
    printf("%lld",sum);
    return 0;
}
