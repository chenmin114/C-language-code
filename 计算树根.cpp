#include<stdio.h>
#include<string.h>
char a[1000005];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0;i < n;i++)
    {
		scanf("%s",&a);
		int sum;
        while (1)
        {
		    sum = 0;
			for (int j=0;a[j] != '\0';j++)
			    sum += a[j] - '0';	
			if (sum <10)
			    break;
			sprintf(a,"%d",sum);	    
		}
    printf("%d\n",sum);

		
	}
	return 0;
}			
