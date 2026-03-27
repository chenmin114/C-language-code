#include<stdio.h>
#define min(x,y) x>y?y:x
#define abs(x) x>0?x:-x
typedef long long ll;
const ll mod=998244353;
int Quick_Gcd(ll x,ll y){
    if(x==0)return y;
    if(y==0)return x;
    if(x&1==0&&y&1==0)return Quick_Gcd(x>>1,y>>1);
    else if(x&1==0)return Quick_Gcd(x>>1,y);
    else if(y&1==0)return Quick_Gcd(x,y>>1);
    else return Quick_Gcd(abs(x-y),min(x,y));
}
int Quick_Pow(ll x,ll y){
    ll re=1;
    while(y){
        if(y&1==1)re=re*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return re;
}
int main(){
    int T;
    scanf("%d",T);
    while(T--){
        ll a,b,c,d;
        scanf("%lld%lld%lld%lld",a,b,c,d);
        int ab=Quick_Pow(a,b);
        int cd=Quick_Pow(c,d);
        int g=Quick_Gcd(ab,cd);
        printf("%d\n",g);
    }
    return 0;
}
