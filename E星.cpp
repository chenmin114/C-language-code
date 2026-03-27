#include <stdio.h>
#include <string.h>
#include <ctype.h>


int f(const char *text, const char *keyword, int start, int len) 
{
    for (int i = 0; i < len; i++) 
	{
        if (tolower(text[start + i]) != keyword[i]) 
		{
            return 0;
        }
    }
    return 1;
}

int main() 
{
    char text[2005];
    int n;
    char keywords[15][55];
    int mark[2005] = {0}; 
    fgets(text, 2005, stdin);
    text[strcspn(text, "\n")] = 0; 
    int textLen = strlen(text);
    scanf("%d", &n);
    getchar(); 
    for (int i = 0; i < n; i++) 
	{
        fgets(keywords[i],55, stdin);
        keywords[i][strcspn(keywords[i], "\n")] = 0; 
    }
    for (int k = 0; k < n; k++) 
	{
        int keyLen = strlen(keywords[k]);
        if (keyLen == 0) 
		    continue;
        for (int i = 0; i <= textLen - keyLen; i++)
		 {
            if (f(text, keywords[k], i, keyLen)) 
			{
                for (int j = 0; j < keyLen; j++) 
				{
                    mark[i + j] = 1; 
                }
            }
        }
    }
    for (int i = 0; i < textLen; i++) 
	{
        if (mark[i]) 
            printf("*");
        else 
            printf("%c", text[i]);
    }
    printf("\n");
    return 0;
}
