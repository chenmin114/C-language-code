#include <stdio.h>
int h[105]={0};
char a[101] = {0}; 
int main() 
{
    int N;
    scanf("%d", &N);  
    for (int i = 0; i < N; ++i) 
	{
        scanf("%d", &h[i]);
    }
    int xb, yb;
    scanf("%d %d", &xb, &yb);
    for (int y = 20; y >= 0; --y) 
	{
        char a[101] = {0};  
        for (int x = 0; x< N;x++) 
		{
            if (y == yb) 
			{
                if (x == xb-1) 
				{	
                    a[x] = '-';
                } 
				else if (x == xb) 
				{
                    a[x] = 'o';
                } 
				else if (x == xb + 1) 
				{
                    a[x] = '-';
                } 
				else 
				{
                    if (y < h[x]) 
					{
                        a[x] = '*';
                    } 
					else if (y == h[x]) 
					{
                        a[x] = '_';
                    } 
					else 
					{
                        a[x] = '.';
                    }
                }
            } 
			else 
			{
                if (y < h[x]) 
				{
                    a[x] = '*';
                } 
				else if (y == h[x]) 
				{
                    a[x] = '_';
                } 
				else 
				{
                    a[x] = '.';
                }
            }
        }
        printf("%s\n", a);  
    }
    return 0;
}
