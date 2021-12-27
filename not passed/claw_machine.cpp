#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100009;
const ll mod = 1e9+7;
ll kawaii[N];
int l,r,k;
int n,q;

void sol()
{
    ll dp[r+9][k+9]; // picking from 1-i : kawaii => number of ways
    for(int i=l-1;i<=l-1;++i) for(int j=0;j<=k;++j) dp[i][j] = 0;
    dp[l-1][0] = 1; // not picking anything ,with 0 cuteness
    for(int i=l;i<=r;++i) // from l to i
    {
        ll cute = kawaii[i];
        for(int j=0;j<=k;++j) // j level kawaii
        {
            dp[i][j] = dp[i-1][j];
            if(j-cute >=0 ) dp[i][j] += dp[i-1][j-cute];
            dp[i][j]%=mod;
        }
    }
    cout << dp[r][k] << endl;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;++i) cin >> kawaii[i];

    while(q--)
    {
        cin >> l >> r >> k;
        sol();
    }



}
