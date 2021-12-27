#include<bits/stdc++.h>
using namespace std;
const int INF = 2e7;
int dp[270];

int main()
{
    int n,k; cin >> n >> k;
    int price[n];
    for(int i=0;i<270;++i) dp[i] = INF;
    for(int i=0;i<n;++i)
    {
        cin >> price[i];
        int cf=1,sum=0;
        for(int j=0;j<k;++j)
        {
            int a; cin >> a;
            sum+=cf*a;
            cf*=2;
        }
        dp[sum] = min(dp[sum],price[i]);
    }
    dp[0] = 0;

    for(int i=1;i<(1<<k);++i)
    {
        for(int j=1;j<=(1<<k);++j)
        {
            dp[i|j] = min(dp[i|j],dp[i]+dp[j]);     /// 0 0 1 1 0 0 1
                                                    /// 1 0 0 1 0 1 1
                                               /// ==   1 0 1 1 0 1 1
        }
    }
    cout << dp[(1<<k)-1];
}
