#include<bits/stdc++.h>
using namespace std;
using ll = long long;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<ll> a(n+9,0);
    for(ll i=1;i<=n;++i) cin >> a[i];
    ll l = 0 ;
    ll r = LONG_MAX;

    while(l<=r)
    {
        bool ok=1;
        ll mid = (l+r)/2;
        vector<ll> v;
        for(ll i=1;i<=n;++i) if(a[i] > mid) v.push_back(a[i]);
   //     cerr << "      mid = " << mid << endl;
     //   for(auto it : v) cerr << it << ' '; cerr << endl;
        for(ll i=0;i<v.size() and ok;i+=2)
        {
            if(v[i] != v[i+1]) ok=0;
        }

        if(ok) r=mid-1;
        else l=mid+1;
    }

    cout << l;
}
