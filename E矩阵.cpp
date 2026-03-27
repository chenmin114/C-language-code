#include <stdio.h>
typedef long long ll;
int n,m;
ll a[2010][2010];
ll s[2010][2010];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%lld",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    int q;
    scanf("%d",&q);
    for(int id=1;id<=q;id++){
        int i1,j1,i2,j2;
        scanf("%d%d%d%d",&i1,&j1,&i2,&j2);
        printf("%lld\n",s[i2][j2]-s[i1-1][j2]-s[i2][j1-1]+s[i1-1][j1-1]);
    }
    return 0;
}    
