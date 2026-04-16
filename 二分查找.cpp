#include <stdio.h>
int a[1000005]={0};

int check(int n,int m) {
    int l=0,r=n-1;
    int ans=-1;
    while (l<=r)
	{
        int mid=l+(r-l)/2;
        if (a[mid]>=m) 
		{
            if (a[mid]==m) 
			{
                ans=mid;
            }
            r=mid-1;
        } 
		else  l=mid+1;
    }
    return (ans==-1) ? -1:ans+1;
}


int main()
{
	int n,m,x;
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	while (m--){
		scanf("%d",&x);
		int ans=check(n,x);
		printf("%d ",ans);
	}
	return 0;
}
