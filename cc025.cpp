#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
ll n; ll sum=0;
ll a[609],qs[609];
ll dp[609][609];

ll mcm(int l,int r)
{
    if(dp[l][r]!=-69) return dp[l][r];
    if(l+1==r) return max(a[l],a[r]) + 2*min(a[l],a[r]);
    ll mx = 0;
    for(int mid = l;mid<r;++mid)
    {
        ll chg1 = qs[mid]-qs[l-1];
        ll chg2 = qs[r]-qs[mid];
        ll big  = max(chg1,chg2);
        ll smol = min(chg1,chg2);
        mx = max(mx,big+2*smol+mcm(l,mid)+mcm(mid+1,r));
    //    cerr << l << ":" << mid << ":" << r << "  " << chg1 << " " << chg2 << " combined to " << big+2*smol << endl;
    }
    dp[l][r] = mx;
    return mx;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;++i){cin >> a[i]; qs[i] = qs[i-1]+a[i];}
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) dp[i][j] = -69;
    mcm(1,n);
    cout << dp[1][n];

}
