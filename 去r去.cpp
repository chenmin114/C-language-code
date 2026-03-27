#include <stdio.h>
#include <string.h>
const char vowels[] = "aeiou";

int main() 
{
    char word[100005];
    scanf("%s", word);
    int length = strlen(word);
    char result[100005];
    int j = 0;
    for (int i = 0; i < length; i++) 
	{

        if (word[i] == 'r' && i > 0) 
		{
            int r = 0;
            for (int k = 0; k < 5; k++) 
			{
                if (word[i - 1] == vowels[k]) 
				{
                    r = 1;
                    break;
                }
            }

            if (r) 
			{
                continue;
            }
        }
        result[j++] = word[i];
    }
    result[j] = '\0';
    printf("%s\n", result);
    return 0;
}
