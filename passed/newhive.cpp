#include<bits/stdc++.h>
using namespace std;
int n,m;
int t[1009][1009];
int hive[1009][1009];
int dp[1009][1009];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int i=0;i<n;++i) for(int j=0;j<m;++j) {cin >> hive[i][j]; dp[i][j] = hive[i][j]; t[i][j] = 1;}

    for(int i=1;i<n;++i) for(int j=0;j<m;++j)
    {
        for(int k=-1;k<=1;++k)
        {
            int ai = j+k;
            if(i%2==0 and k==1) continue;
            if(i%2==1 and k==-1) continue;
            if(ai>=m or ai<0) continue;
            if(dp[i-1][ai] + hive[i][j] > dp[i][j])
            {
                dp[i][j] = dp[i-1][ai]+hive[i][j];
                t[i][j] = t[i-1][ai];
            }
            else if(dp[i][j] == dp[i-1][ai]+hive[i][j]) t[i][j]+=t[i-1][ai];
        }
    }
    int mx=-1,cnt=1;
    for(int j=0;j<m;++j)
    {
        if(dp[n-1][j]>mx) mx=dp[n-1][j],cnt=t[n-1][j];
        else if(dp[n-1][j]==mx) cnt+=t[n-1][j];
    }

    cout << mx << " " << cnt;
}
