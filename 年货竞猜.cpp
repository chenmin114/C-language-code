//春节将至，蓝桥学院组织了一场热闹的 "年货智力竞猜" 活动！活动现场摆放了一份超级年货大礼包，谁能最快答对下面的数学谜题，就能把这份装满各种年货的大礼包抱回家！小蓝作为主持人，每次竞猜会给出一个正整数 n，并定义了 f(n,k)= i=1∑n?(imodk)其中 imodk 表示 i 除以 k 的余数。小蓝的问题是：在所有可能的正整数 k 中，有多少个 k 能让 f(n,k) 恰好被 k 整除？最快答对的同学就能赢得这份诱人的年货大礼包，请你来尝试回答小蓝的每次询问吧。

#include <stdio.h>
// 用于存储质因子的结构体，模拟 C++ 中的 map
// 由于 n <= 10^9，质因子不会太多，数组大小开大一点即可
typedef struct {
    long long prime;
    int exp;
} Factor;
Factor factors[100];
int factor_count=0;

// 分解质因数函数
void prime_factorize(long long x) 
{
    for (long long i=2;i*i<=x;i++) 
	{
        if (x%i==0) 
		{
            int cnt=0;
            while (x%i==0) 
			{
                x/=i;
                cnt++;
            }
            // 记录找到的质因子
            factors[factor_count].prime=i;
            factors[factor_count].exp=cnt;
            factor_count++;
        }
    }
    // 如果 x 还是大于 1，说明剩下一个大的质数
    if (x>1) 
	{
        factors[factor_count].prime=x;
        factors[factor_count].exp=1;
        factor_count++;
    }
}

void solve() 
{
    long long n;
    if (scanf("%lld",&n)!=1) 
	    return;
    factor_count=0; // 每次清空因子记录
    // 核心思路：求 n(n+1)/2 的约数个数
    // 为了避免处理大数 n(n+1)/2，我们利用 n 和 n+1 互质的性质
    // 将 2 的除法分配到 n 或 n+1 上
    long long num1=n;
    long long num2=n+1;
    if (num1%2==0) {
        num1/=2;
    } 
	else  num2/=2;
    // 分别分解两个较小的数
    prime_factorize(num1);
    prime_factorize(num2);
    // 根据约数个数定理计算结果
    // 约数个数 = (指数1 + 1) * (指数2 + 1) * ...
    long long ans=1;
    for (int i=0;i<factor_count;i++){
        ans*=(factors[i].exp+1);
    }

    printf("%lld\n",ans);
}

int main() 
{
    int t;
    if (scanf("%d",&t)==1) 
	{
        while (t--) 
		{
            solve();
        }
    }
    return 0;
}
