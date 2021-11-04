#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mxn = 1e5+9;
const ll mod = 1e9+7;
ll a[mxn];
ll dp[mxn][mxn];
ll qs[mxn];

int main()
{
    int n,q; cin >> n >> q;
    for(int i=1;i<=n;++i) {cin >> a[i];qs[i]=qs[i-1]+a[i];}

}
