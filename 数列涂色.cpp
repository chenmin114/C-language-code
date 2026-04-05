
#include <stdio.h>
#define INF 1e18
int q[100005];
long long arr[100005];
long long dp[100005];

int main() {
    int n = 0, k = 0;
    if (scanf("%d %d", &n, &k) != 2) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    int head = 0, tail = 0;
    q[tail++] = 0;
    dp[0] = arr[0];
    for (int i = 1; i < n; i++) 
	{
        while (head < tail && q[head] < i - (k + 1))
		{
            head++;
        }
        if (head < tail) 
		{
            dp[i] = arr[i] + dp[q[head]];
        } 
		else 
		{
            dp[i]=INF;
        }
        while (head < tail && dp[q[tail - 1]] >= dp[i]) 
		{
            tail--;
        }
        q[tail++] = i;
    }
    printf("%lld\n", dp[n - 1]);
    return 0;
}
