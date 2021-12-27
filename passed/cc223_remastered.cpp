#include<bits/stdc++.h>
using namespace std;


bool a[7009][7009];
int day[7009];
int dp[7009][7009];
const int INF = INT_MAX-70009;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    int sum = n*m;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            char t; cin >> t; t-=48;
            a[i][j] = t;

            if(t)dp[i][j] = INF;

        }
    }

    for(int i=n;i>=1;--i)
    for(int j=m;j>=1;--j)
    {
        dp[i][j] = min({dp[i][j] , dp[i+1][j]+1 , dp[i+1][j+1]+1 , dp[i][j+1]+1});
        day[dp[i][j]]++;
    }

    for(int i=0;i<min(n,m);++i)
    {
        sum-=day[i];
        cout << sum << endl;
    }



}
