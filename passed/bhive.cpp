#include<bits/stdc++.h>
using namespace std;
int hive[1009][1009];
int dp[1009][1009];
int t[1009][1009];
int mve[2][2] = {{0,1},{-1,0}};
int main()
{
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin >> hive[i][j];
    for(int i=1;i<=m;++i) dp[1][i] = hive[1][i];
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            int coef = i%2;
            for(int k=0;k<2;++k)
            {
                int ax = i-1;
                int ay = j+mve[coef][k];
                if(ax < 1 or ay < 1 or ax > n or ay > m) continue;
                dp[i][j] = max(hive[i][j]+)

            }
        }
    }
}
