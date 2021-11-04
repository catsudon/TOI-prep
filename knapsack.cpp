#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
int member[10009],val[10009];
pii dp[5009][15009];

int main()
{
    int n,t; cin >> n >> t;
    for(int i=1;i<=n;++i) cin >> val[i];
    for(int i=1;i<=n;++i) cin >> member[i];

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=t;++j)
        {
            int mb = 8*(member[i]+dp[i-1][j].s);
            dp[i][j] = dp[i-1][j];
            if(val[i]+dp[i-1][max(j-mb,0)].f > dp[i][j].f)
                dp[i][j] = {val[i]+dp[i-1][j-mb].f,dp[i-1][j-mb].s+1};

        }
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=t;++j) cerr << dp[i][j].f << ":" << dp[i][j].s  << " ";
        cerr << endl << endl;
    }
    cout << dp[n][t].f;

}
