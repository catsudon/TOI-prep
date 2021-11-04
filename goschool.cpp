#include<bits/stdc++.h>
using namespace std;
long long dp[90][90];
int main()
{
    int n,m,o; cin >> n >> m >> o;
    while(o--)
    {
        int a,b; cin >> a >> b;
        dp[a][b] = -1;
    }
    dp[1][1] = 1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(dp[i][j] == -1) dp[i][j]=0;
            else dp[i][j] += dp[i-1][j] + dp[i][j-1];
        }
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j) cerr << dp[i][j] << " ";
        cerr << endl;
    }
    cout << dp[n][m];
}
