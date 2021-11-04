#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
const int INF = 1e9+9;
int dp1[1009][1009]; /// from finish to start
int field[1001][1001];
int d[3] = {-1,0,1};
int main()
{
    int n,m; cin >> n >> m;
    queue<pair<pii,pii> > q; // sum:car :: x:y
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin >> field[i][j];
    for(int i=0;i<=1005;++i) for(int j=0;j<=1005;++j) dp1[i][j] = INF;
    for(int i=0;i<=1005;++i) dp1[i][0] = 0;

    for(int j=1;j<=m;++j)
    {
        for(int i=1;i<=n;++i)
        {
            dp1[i][j] = field[i][j] + dp1[i][j-1];
            for(int k=0;k<=2;++k)
            {
                int ai = i+d[k];
                if(ai < 1 or ai > n) continue;
                dp1[i][j] = min(dp1[i][j],field[i][j]+dp1[ai][j-1]);
            }
        }
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=m+1;++j) cerr << dp1[i][j] << " ";
        cerr << endl;
    }


    for(int i=1;i<=n;++i)
    {
        int ans = dp1[i][m];
        if(i-1 >= 1) ans = min(ans,dp1[i-1][m]);
        if(i+1 <= n) ans = min(ans,dp1[i+1][m]);

        cout << ans << endl;
    }


}
