#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);
    while (n--) 
	{
        int num;
        scanf("%d",&num);
        int count=0;
        int t=num;
        // 处理质因子2
        if (t%2==0) {
            count++;
            while (t%2==0) 
			{
                t/=2;
            }
        }
        // 处理奇数质因子，从3开始，步长为2
        for (int i=3;i*i<=t;i+=2) {
            if (t%i==0) 
			{
                count++;
                while (t%i==0) 
				{
                    t/=i;
                }
            }
        }
        if (t>2) 
		{
            count++;
        }
        printf("%d\n",(count==2) ? 1 : 0);
    }
    return 0;
}
