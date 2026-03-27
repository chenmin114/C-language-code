#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[200005];
int p[1000006];
int n;
long long k;

long long le(int max_val) 
{
    memset(p, 0, sizeof(p));
    int distinct = 0;
    long long cnt = 0;
    int l = 0;
    for (int r = 0; r < n; r++) 
	{
        p[a[r]]++;
        if (p[a[r]] == 1) distinct++;
        while (distinct > max_val) 
		{
            p[a[l]]--;
            if (p[a[l]] == 0) distinct--;
            l++;
        }
        cnt += (r - l + 1);
    }
    return cnt;
}

typedef struct 
{
    int l, r;
} Segment;

Segment segs[200005];
int seg_cnt;

void eq(int exact_val) 
{
    memset(p, 0, sizeof(p));
    int distinct = 0;
    seg_cnt = 0;
    int l1 = 0, l2 = 0;
    for (int r = 0; r < n; r++) 
	{
        p[a[r]]++;
        if (p[a[r]] == 1) distinct++;
        while (distinct > exact_val) 
		{
            p[a[l1]]--;
            if (p[a[l1]] == 0) distinct--;
            l1++;
        }
        while (l2 <= r && distinct == exact_val) 
		{
            p[a[l2]]--;
            if (p[a[l2]] == 0) distinct--;
            l2++;
        }
        for (int ll = l1; ll < l2; ll++) {
            segs[seg_cnt].l = ll;
            segs[seg_cnt].r = r;
            segs[seg_cnt].l++; 
            segs[seg_cnt].r++;
            seg_cnt++;
        }
        for (int ll = l1; ll < l2; ll++) 
		{
            p[a[ll]]++;
            if (p[a[ll]] == 1) distinct++;
        }
    }
}

int cmp(const void *aa, const void *bb) 
{
    Segment *a = (Segment*)aa;
    Segment *b = (Segment*)bb;
    if (a->l != b->l) return a->l - b->l;
    return a->r - b->r;
}

void solve() {
    scanf("%d %lld", &n, &k);
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &a[i]);
    }
    int low = 1, high = n, m = 0;
    while (low <= high) 
	{
        int mid = (low + high) / 2;
        if (le(mid) >= k) 
		{
            m = mid;
            high = mid - 1;
        } 
		else 
		{
            low = mid + 1;
        }
    }
    long long prev_count = (m > 1) ? le(m - 1) : 0;
    long long idx_in_m = k - prev_count;
    eq(m);
    qsort(segs, seg_cnt, sizeof(Segment), cmp);
    printf("%d %d\n", segs[idx_in_m - 1].l, segs[idx_in_m - 1].r);
}

int main() 
{
    int t;
    scanf("%d", &t);
    while (t--) 
	{
        solve();
    }
    return 0;
}
