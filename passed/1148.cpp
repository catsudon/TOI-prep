#include<bits/stdc++.h>
using namespace std;
long long dp[2][50009];
long long getto[50009];
long long chob[50009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin >> n >> m >> k;
    int last = 0;
    for(int i=1;i<=m;++i)
    {
        int a; cin >> a;
        getto[i]=a-last;
        last=a;
    }
    m++; getto[m] = n-last;
    for(int i=1;i<=k;++i) cin >> chob[i];

    for(int i=1;i<=k;++i)
    {
        int now = i%2;
        int pre = !now;
        dp[now][i-1] = 0;
        for(int j=i;j<=m-(k-i);++j)
        {
            dp[now][j] = max({dp[pre][j-1]+(getto[j]*chob[i]) , dp[now][j-1]+(getto[j]*chob[i])} );
         //   cerr << i << ' ' << j << "     " << dp[now][j] << "    " << (getto[j]*chob[i]) << " + " << dp[pre][j-1] << "  /  " << dp[now][j-1] << endl;
        }
       // cerr << endl;
    }

    cout << dp[k%2][m];
}
