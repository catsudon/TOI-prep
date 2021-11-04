#include<bits/stdc++.h>
using namespace std;
#define N 1e6+7
int dp[50009]; // in this amount of money there are ... ways to use
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    int item[n];
    for(int i=0;i<n;++i) cin >> item[i];
    dp[0] = 1;
    for(int i=0;i<n;++i)
    {
        for(int j=m;j>=item[i];--j)
        {
            dp[j] += dp[j-item[i]];
            dp[j]%=1000007;
        }
    }


    cout << dp[m];

}
