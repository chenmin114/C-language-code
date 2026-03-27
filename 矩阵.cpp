#include <stdio.h>

int main() 
{
    int n, q; 
    int arr[1145]; 
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; scanf("%d", arr + i++));   
    while (q--) 
	{
        int op, x, y, sum; 
        scanf("%d%d%d", &op, &x, &y);
        switch (op) 
		{
            case 1: if (x != y) arr[x] = arr[y]; break;
            case 2: if (x != y) { int t = arr[x]; arr[x] = arr[y]; arr[y] = t; } break;
            case 3: arr[x] += y; break;
            case 4: arr[x] = y; break;
            case 5: printf("%d\n", arr[x] - arr[y]); break;
            case 6: sum = 0; for (int i = x; i <= y; sum += arr[i++]); printf("%d\n", sum);
        }
    }
    return 0;
}
