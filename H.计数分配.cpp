#include <stdio.h>

int n, k;
int a[200005];
int visit[200005];
int time;

void visits() 
{
    time++;
}

int is_visited(int color) 
{
    return visit[color]==time;
}

void mark_visited(int color) 
{
    visit[color]=time;
}

int check(int x) 
{
    visits();
    int distinct = 0;
    int cnt = 0;    
    for (int i = 0; i < n; i++) 
	{
        if (!is_visited(a[i])) 
		{
            distinct++;
            mark_visited(a[i]);
        }
        if (distinct == x) 
		{
            cnt++;
            distinct = 0;
            visits(); 
        }
    }
    return cnt >= k;
}

int solve() 
{
    int left = 1, right = n, ans = 1;
    while (left <= right) 
	{
        int mid = (left + right) / 2;
        if (check(mid)) 
		{
            ans = mid;
            left = mid + 1;
        } 
		else 
		{
            right = mid - 1;
        }
    }
    return ans;
}

int main() 
{
    int t;
    scanf("%d", &t);
    time = 0;
    for (int i = 0; i<200005; i++)
        visit[i] = 0;   
    while (t--) 
	{
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) 
		{
		    scanf("%d", &a[i]);
		}
        int ans =solve();
        printf("%d\n", ans);
    }
    return 0;
}
