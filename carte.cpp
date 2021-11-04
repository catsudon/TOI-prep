#include<bits/stdc++.h>
#define cost first
#define used second
const int INF = 1e9;
using namespace std;
using pii = pair<int,int>; /// cost  :: used
pii dp[500][500]; /// L : R
int a[500];
int k,mx=0;

int solve()
{
    int n; cin >> n;
    for(int i=0;i<n;++i) cin >> a[i];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(j==i) dp[i][j]  = {1,1};
            else dp[i][j] = {INF,INF};
        }
    }
    for(int coef = 1;coef < n;coef++)
    {
        for(int i=0;i<n;++i)
        {
            int j = i + coef;
            dp[i][j] = {dp[i+1][j].cost+1,1};
            for(int l = i;l < j and j < n;++l)
            {
                if(a[i] == a[l])
                {
                    pii temp = {dp[i][l].cost + dp[l+1][j].cost-1,dp[i][l].used+1};
                    if(temp.used > k) temp.used = 1,temp.cost++;
                    dp[i][j] =  min(dp[i][j],temp);
                }
              cerr  << i << " " << j << " " << l << " " << dp[i][j].cost << " " << dp[i][j].used << endl;
            }
        }
    }
    mx = max(dp[0][n-1].cost,mx);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int o; cin >> o >> k;
    while(o--) solve();

    cout << mx;
}
