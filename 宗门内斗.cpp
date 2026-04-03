#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[500005];   // first 存值，second 存原始索引
bool cmp(const pair<int,int> &x,const pair<int,int> &y) 
{
    if (x.first!=y.first) 
        return x.first>y.first;   // 优先按 first 降序
    return x.second<y.second;      // first 相同时按 second 升序
}

int main() 
{
    ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) 
	{
        cin >> a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1,cmp);   
    for (int i=1;i<=n;i++) 
	{
       if(a[i].second==k)
	   {
            if(i==2 || i==1){
				cout<<i;
			    return 0;
			}
            if(a[i].first==a[1].first)
			{
				cout<<k;
				return 0;
			}
            if(i>2){
                int p=0;
                for(int j=i-1;a[j].first!=a[1].first;j--)
				{
                    int temp=(k<a[j].second) ? 0:1;
                    p+=(a[j].first-a[i].first +  temp);
                    if(p>m)
					{
						p-= a[j].first-a[i].first+temp;
						break;
					} 
					else {
						a[j].first=a[i].first-1;
					}
                }
            } 
			else 
			{  
			    cout << i;
				return 0; 
			} 
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
	{
        if(a[i].second==k)
		{
            cout<<i;
            return 0;
        }
    }
    return 0;
}
