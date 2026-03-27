#include <stdio.h>

int main() 
{
    for (int i = 100; i <= 999; i++) 
	{
        int a = i / 100;        
        int b = (i / 10) % 10;  
        int c = i % 10;         
        int sum = a * a * a + b * b * b + c * c * c;  
        if (i % sum == 0) 
		{
            printf("%d\n", i);
        }
    }
    return 0;
}
