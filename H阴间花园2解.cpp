#include <stdio.h>
#include <string.h>
int n, k;
int a[200005];
int visit[200005]; 


int check(int x, int timestamp) 
{
    int distinct = 0;
    int cnt = 0;   
    for (int i = 0; i < n; i++) 
	{
        if (visit[a[i]] != timestamp) 
		{
            distinct++;
            visit[a[i]] = timestamp;
        }
        
        if (distinct == x) 
		{
            cnt++;
            distinct = 0;
            timestamp++; 
        }
    }
    return cnt>=k;
}

int solve(int n,int k) 
{
    int left = 1, right = n, ans = 1;
    int timestamp_base = 1; 
    while (left <= right) 
	{
        int mid = (left + right) / 2;
        if (check(mid, timestamp_base)) 
		{
            ans = mid;
            left = mid + 1;
        } 
		else 
		{
            right = mid - 1;
        }
        timestamp_base += n; 
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) 
	{
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) 
		{
		    scanf("%d", &a[i]);
		}
        int ans=solve(n,k);
        printf("%d\n",ans);
    }
    return 0;
}
