#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a ,const void *b)
{
    return *(int *)a > *(int *)b;//将数组升序排序
}

// counts[p]存储每个数包含质因子 p 的个数
int *counts[100005];
// 记录哪些质因子出现过
int pi[100005];
int pcount=0;

int main() 
{
    int n;
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    for (int i=0; i<n;i++) {
        scanf("%d", &a[i]);
    }
    // 1. 质因数分解
    for (int i=0;i < n;i++) 
	{
        int num=a[i];
        for (int p=2;p*p<=num;p++) 
		{
            if (num%p==0) 
			{
                int cnt=0;
                while (num%p==0) 
				{
                    cnt++;
                    num/=p;
                }
                // 如果这个质因子 p 还没被记录过
                if (counts[p]==NULL) {
                    counts[p]=(int *)calloc(n,sizeof(int)); // 初始化为 0
                    pi[pcount++]=p;
                }
                counts[p][i]=cnt;
            }
        }
        // 如果 num > 1，说明剩下的 num 本身就是一个质数
        if (num > 1) 
		{
            int p=num;
            if (counts[p]==NULL) 
			{
                counts[p]=(int *)calloc(n,sizeof(int));
                pi[pcount++]=p;
            }
            counts[p][i]=1;
        }
    }
    long long sum=0;
    int *e=(int *)malloc(n * sizeof(int));
    // 2. 对每个质因子计算最小花费
    for (int i=0;i<pcount;i++) 
	{
        int p=pi[i];
        int *arr=counts[p];
        for (int j=0;j<n;j++) 
		{
            e[j]=arr[j];
        }
        // 排序以找到中位数
        qsort(e,n,sizeof(int),cmp);
        // 找到中位数
        int m=e[n / 2];
        // 计算总花费
        for (int j=0;j<n;j++) 
		{
            sum+=abs(e[j]-m);
        }
    }
    printf("%lld\n",sum);
    // 释放内存
    free(a);
    free(e);
    for (int i=0;i<pcount;i++) 
	{
        free(counts[pi[i]]);
    }
    return 0;
}
