#include <stdio.h>
#include <string.h>
      

int main() {
    char fruits[1005][105] = {0};  
    int count = 0;                           
    char now[105];                
    while (scanf("%s", now) != EOF) 
	{
        int flag = 0;  
        for (int i = 0; i < count; i++) 
		{
            if (strcmp(fruits[i], now) == 0) 
			{
                flag = 1;
                break;
            }
        }
        if (flag) 
		{
            printf("Not Applicable\n");
        } 
		else 
		{
            printf("Delicious!\n");
            strcpy(fruits[count], now); 
            count++;
        }
    }

    return 0;
}
