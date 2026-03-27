#include <stdio.h>

int main() 
{
    long long a, b;
    scanf("%lld %lld", &a, &b);
    long long c = a / b;      
    long long d = a % b;       
    long long floor, ceil;
    
    if (d == 0) 
	{

        floor = ceil = c;
    } else {
        if (a * b > 0) {
            // 被除数和除数同号时
            floor = c;
            ceil = c + 1;
        } else {
            // 被除数和除数异号时
            floor = c - 1;
            ceil = c;
        }
    }
    
    printf("%lld %lld\n", floor, ceil);
    return 0;
}
