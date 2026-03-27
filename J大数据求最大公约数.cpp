#include <stdio.h>
typedef long long ll;
const ll p=998244353;
int qpow(int a, long long b, int p)
{
int ans = 1;
int base = a;
while (b > 0)
{
if (b & 1)
{
ans = ans * (long long)base % p;
}
base = (long long)base * base % p;
b >>= 1;
}

return ans;
}
ll gcd2(ll a,ll b){
if(b==0) return a;
else return gcd2(b,a%b);
}
ll gcd4(ll a,ll b,ll c,ll d){
if(b>d) return gcd4(c,d,a,b);
ll g=gcd2(a,c);
if(g==1) return 1;
// now, b<=d.
if(b==0) return 1;
return qpow(g%p,b)*gcd4(a/g,b,g,d-b)%p;
}
int main(){
int T;
scanf("%d",&T);
while(T--){
ll a,b,c,d;
scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
printf("%lld\n",gcd4(a,b,c,d));
}
return 0;
}
