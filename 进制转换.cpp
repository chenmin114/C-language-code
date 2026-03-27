#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int p, q, m;
    char s[1005];  
    scanf("%d", &p);
    scanf("%s", s);
    scanf("%d %d", &q, &m);
    double dec = 0.0;
    int len = strlen(s);
    for (int i = 2; i < len; ++i) 
	{  
        int digit = s[i] - '0';      
        dec += digit * pow(p, -(i - 1));  
    }
    
    printf("0.");
    for (int i = 0; i < m; ++i) 
	{
        dec *= q;             
        int d = (int)dec;     
        printf("%d", d);
        dec -= d;            

        if (dec == 0.0) 
		{
            for (int j = i + 1; j < m; ++j) 
			{
                printf("0");
            }
            break;
        }
    }
	printf("\n");  
    return 0;
}
