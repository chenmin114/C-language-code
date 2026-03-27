#include <stdio.h>
#include <stdlib.h>

#define MAXN 500005

typedef long long ll;
int h[MAXN];
int result[MAXN];

int visible(int i, int j, int k) 
{
    return (ll)(h[k] - h[i]) * (j - i) < (ll)(h[j] - h[i]) * (k - i);
}

int main() 
{
	int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &h[i]);
    }
    int stack[MAXN];
    int top = -1;
    for (int i = n - 1; i >= 0; i--) 
	{
        while (top > 0) 
		{
            int top1 = stack[top];     
            int top2 = stack[top - 1]; 
            if (visible(i, top2, top1)) 
			{
                top--; 
            } 
			else 
			{
                break;
            }
        }
        if (top >= 0) {
            result[i] = stack[top];
        } else {
            result[i] = i; 
        }      
        stack[++top] = i;
    }
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", result[i] + 1);
    }
    
    return 0;
}
