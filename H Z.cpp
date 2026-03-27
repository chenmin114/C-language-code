#include <stdio.h>
#include <math.h>


long long z_path(int n, int x, int y) 
{
    if (n == 0) 
	    return 1;
    int size = 1 << (n - 1);
    long long block = (long long)size * size;
    if (x < size && y < size) 
	{
        return z_path(n - 1, y, x);
    } 
	else if (x < size && y >= size) 
	{
        return block + z_path(n - 1, x, y - size);
    } 
	else if (x >= size && y < size) 
	{
        return 2 * block + z_path(n - 1, x - size, y);
    } 
	else 
	{
        return 3 * block + z_path(n - 1, size - 1 - y, size - 1 - x);
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
    int size = 1 << n;
    for (int i = 0; i < size; i++) 
	{
        for (int j = 0; j < size; j++) 
		{
            printf("%lld", z_path(n, i, j));
            if (j < size - 1) 
			    printf(" ");
        }
        printf("\n");
    }
    return 0;
}
