#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    ll choco[n+9];
    vector<ll> dp(n+9,0);
    for(ll i=1;i<=n;++i) {cin >> choco[i];}

    dp[1] = choco[1];
    for(ll i=2;i<=n;++i)
    {

        dp[i] = max(dp[i-1],choco[i]+dp[i-2]);
    }

    cout << dp[n];


}
