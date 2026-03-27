#include <stdio.h>
#include <math.h>

typedef long long ll;
ll x[8],y[8],z[8];
ll s(int i,int j)
{
	return pow((x[i]-x[j]),2) +pow((y[i]-y[j]),2)+pow((z[i]-z[j]),2);
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		ll t = 1e13;
		for (int i=0;i<8;i++)
		{
			scanf("%lld %lld %lld",&x[i],&y[i],&z[i]);
			if (i)
			{
				if (s(i,0)<t)
				    t = s(i,0);
			}
		}
		int flag =1;
		for (int i=0;i<8;i++)
		{
			int cnt[4]={0};
			for (int j=0;j<8;j++)
			{
				ll d =s(i,j);
				if (d%t!=0 || d/t>3){
				    flag = 0;
				    break;
			}
			++cnt[d/t];
		    }
		    if (flag==0 || cnt[0]!=1 || cnt[1]!=3 || cnt[2]!=3 || cnt[3]!=1)
		    {
			    flag=0;
			    break;
		    }
		}    
		if (flag)
		    printf("cubic\n");
		else
		    printf("non-cubic\n");    
	}
	return 0;
}    
