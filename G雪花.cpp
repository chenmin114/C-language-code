#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXSIZE 6561
char snow[6566][6567]; 

void basic(int x, int c) 
{
    snow[x][c] = '\\';
    snow[x][c + 2] = '/';
    snow[x + 1][c + 1] = 'x';
    snow[x + 2][c] = '/';
    snow[x + 2][c + 2] = '\\';
}

void draw(int x, int c, int t) 
{
    if (t == 1) 
	{
        basic(x, c);
        return;
    }
    int size = 1;
    for (int i = 1; i < t; i++) size *= 3; 
    draw(x, c, t - 1); // 左上
    draw(x, c + 2 * size, t - 1); // 右上
    draw(x + size, c + size, t - 1); // 中间
    draw(x + 2 * size, c, t - 1); // 左下
    draw(x + 2 * size, c + 2 * size, t - 1); // 右下
}

int main() 
{
    int t;
    scanf("%d", &t);
    if (t == 0) 
	{
        printf("x\n");
        return 0;
    }    
    int n = 1;
    for (int i = 0; i < t; i++) 
	    n *= 3; 
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
		{
            snow[i][j] = ' ';
        }
        snow[i][n] = '\0'; 
    }    
    draw(0, 0, t);
    for (int i = 0; i < n; i++) 
	{
        printf("%s\n", snow[i]);
    }
    
    return 0;
}
