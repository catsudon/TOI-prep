#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    ll n; cin >> n;
    vector<pll> v;
    long long sum = 0;
    for(ll i=1;i<n*2;++i)
    {
        ll a,b; cin >> a >> b;
        sum += a;
        b+=a;
        v.push_back({-b,i});
    }
    ll chg=0;
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i) chg-=v[i].first;

    if(chg < sum/2) cout << -1;
    else for(int i=0;i<n;++i) cout << v[i].second << ' ';
}
