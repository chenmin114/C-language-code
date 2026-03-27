#include <stdio.h>

int main() 
{
    int n, m;
    scanf("%d %d", &n, &m);   
    int a[105] = {0};  
    int count = 0;       
    int outnum = 0;        
    int x = 0;            
    while (outnum < n) 
	{
        if (!a[x]) 
		{  
            count++;
            if (count == m) 
			{
                printf("%d ", x + 1);  
                a[x] = 1;         
                outnum++;
                count = 0;           
            }
        }
        x = (x + 1) % n;  
    }    
    return 0;
}
