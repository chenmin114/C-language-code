#include <stdio.h>
int a[500005];
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int x;
        scanf("%d", &x);
        int l = -1, r = n;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            if (a[mid] < x)
                l = mid;
            else
                r = mid;
        }
        int lft = r; // a[lft] >= x
        l = -1, r = n;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            if (a[mid] <= x)
                l = mid;
            else
                r = mid;
        }
        int rt = r; // a[rt] > x
        printf("%d\n", rt - lft);
    }
    return 0;
}
