#include <stdio.h>
#include <string.h>
#include <math.h>


int change(char c) 
{
    if (c >= '0' && c <= '9') 
	{
        return c - '0';
    } 
	else if (c >= 'a' && c <= 'g') 
	{
        return c - 'a' + 10;
    }
    return -1; 
}

long long f(char *s)
{ 
    int len = strlen(s);
    int base;
    char Char = s[len - 1];
    if (Char >= '0' && Char <= '9') {
        base = Char - '0';
    } 
	else
	 {
        base = Char - 'a' + 10;
    }

    long long sum = 0;
    for (int i = 0; i < len - 1; i++) { // 遍历数字部分（排除最后一位进制标识）
        int num = change(s[i]);
        sum = sum * base + num;
    }
    return sum;
}

int main() 
{
    int n;
    scanf("%d", &n);
    getchar(); 
    while (n--) 
	{
        char s[105];
        fgets(s, sizeof(s), stdin);

        if (s[strlen(s) - 1] == '\n') 
		{
            s[strlen(s) - 1] = '\0';
        }
        long long ans = f(s);
        printf("%lld\n", ans);
    }
    return 0;
}
