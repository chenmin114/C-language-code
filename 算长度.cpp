#include<stdio.h>
int length[25]={0};
int main()
{
    int n,max,min,sum;
    double ans,average;
    sum = 0;
    scanf("%d",&n);
    for (int i = 0;i < n;i++)
    {
		scanf("%d",&length[i]);
		sum += length[i];
    }
    max = min = length[0];
	for (int i=0;i < n;i++)	
    {
		if (length[i] > max)
		    max = length[i];
		if (length[i] < min)
			min = length[i];   
	}
	
	average = ((sum - min - max) * 1.0)/(n-2);
	int t =(int)(average*100);
	ans = t/100.0;
    printf("%.2f",ans);
	return 0;

}
