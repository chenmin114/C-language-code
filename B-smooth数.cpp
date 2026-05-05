#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// is_prime[i] = true 表示 i 是质数
bool is_prime[1000005];
bool is_smooth[1000005];

// 使用埃拉托斯特尼筛法预处理质数
void sieve(int limit) 
{
    // 初始化：假设 0 到 limit 都是质数
    memset(is_prime, true, sizeof(bool) * (limit + 1));
    // 0 和 1 不是质数
    is_prime[0] = false;
    is_prime[1] = false;
    for (int p=2;p*p<=limit;p++) {
        if (is_prime[p]) 
		{
            // 将 p 的所有倍数标记为非质数
            for (int i= p*p;i<=limit;i+=p) {
                is_prime[i]=false;
            }
        }
    }
}

int main() 
{
    int n,B;
    scanf("%d %d",&n,&B);
    // 1. 找出 1 到 n 范围内的所有质数
    sieve(n);
    // 2. 初始化状态
    // 假设 1 到 n 所有数都是 B-smooth
    for (int i = 1; i <= n; i++) {
        is_smooth[i] = true;
    }
    for (int p=B+1;p<=n;p++) {
        if (is_prime[p]) {
            // p 是一个大于 B 的质数。
            // p 的所有倍数 (p, 2p, 3p...) 都含有质因子 p，因此都不是 B-smooth。
            for (int j=p;j<=n;j+=p) 
			{
                is_smooth[j]=false;
            }
        }
    }
    int count=0;
    for (int i=1;i<=n;i++) 
	{
        if (is_smooth[i]) 
		{
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
