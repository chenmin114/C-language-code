#include <stdio.h>
#include <string.h>

long long memo[15]; 
int count = 0;          
int current_indent = 0; 

void print_indent() 
{
    for (int i = 0; i < current_indent; i++) 
	{
        printf("|   ");
    }
}

long long f(int n, int op) 
{
    count++;
    print_indent();
    printf("calculate begin f(%d)\n", n);
    current_indent++;
    if (op == 1 && memo[n] != -1) 
	{
        current_indent--;
        print_indent();
        printf("calculated before return f(%d) = %lld\n", n, memo[n]);
        return memo[n];
    }
    long long result;
    if (n == 3) 
	{
        result = 1;
    } else 
	{
        long long fn = 0;
        for (int i = 3; i <= n; i++) 
		{
            if (i == 3 || i == n) 
			{
                fn += f(n - 1, op);
            } 
			else 
			{
                fn += f(n - i + 2, op) * f(i - 1, op);
            }
        }
        result = fn;
    }
    if (op == 1) 
	{
        memo[n] = result;
    }
    current_indent--;
    print_indent();
    printf("calculate end return f(%d) = %lld\n", n, result);    
    return result;
}

int main() {
    int op, n;
    scanf("%d %d", &op, &n);
    for (int i = 0; i < 15; i++) {
        memo[i] = -1;
    }
    count = 0;
    current_indent = 0;
    long long result = f(n, op);
    printf("answer f(%d) = %lld\n", n, result);
    printf("total function invoked count = %d\n", count);    
    return 0;
}
