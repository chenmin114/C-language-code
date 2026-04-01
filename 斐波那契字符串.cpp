#include <iostream>
using namespace std;
const int MOD=1e9+7;
long long cnt0[100005]={0};
long long cnt1[100005]={0};
long long dp[100005]={0};

void previous()
{
  cnt0[1]=1;
  cnt1[1]=0;
  cnt0[2]=0;
  cnt1[2]=1;
  for(int i=3;i<=100005;i++)
  {
      cnt0[i]=(cnt0[i-1]+cnt0[i-2])%MOD;
      cnt1[i]=(cnt1[i-1]+cnt1[i-2])%MOD;
      long long cross=(cnt1[i-2]*cnt0[i-1])%MOD;
      dp[i]=(dp[i-1]+dp[i-2]+cross)%MOD;
  }
}

int main ()
{
    int t;
    cin >> t;
    previous();
    while(t--)
	{
        int n;
        cin>>n;
        cout<<dp[n]<<endl;    
	}
    return 0;
}
