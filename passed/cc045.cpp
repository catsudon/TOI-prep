#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long qs[100009];
long long dp[100009][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;++i)
    {
        cin >> qs[i];
        qs[i]+=qs[i-1];
      //  cerr << qs[i] << ' ';
    }
   // cerr << endl;

    for(int fam=1;fam<=m;++fam)
    {
        int cur = fam%2;
        int pre = (fam-1)%2;
        for(int i=1;i<=n;++i)
          // maximum value from ( family 1-->fam with index 1-->i)
            dp[i][cur] = max(dp[max(0,i-k)][pre] + (qs[i]-qs[max(0,i-k)]) , dp[i-1][cur]);
    }

    cout << dp[n][m%2];
}
