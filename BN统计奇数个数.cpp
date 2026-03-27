#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  
    int xor_result = 0;
    for (int i = 0; i < n; i++) 
	{
        int num;
        scanf("%d", &num);  
        xor_result ^= num;
    }
    if (xor_result == 0) 
	{
        printf("0\n");
        return 0;
    }
    int lowbit = xor_result & -xor_result;
    int a = 0, b = 0;
    rewind(stdin); 
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) 
	{
        int num;
        scanf("%d", &num); 
        if (num & lowbit) 
		{
            a ^= num; 
        } 
		else 
		{
            b ^= num; 
        }
    }
    if (a < b) 
	{
        printf("%d %d\n", a, b);
    } 
	else 
	{
        printf("%d %d\n", b, a);
    }

    return 0;
}
