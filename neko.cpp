#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,mid; cin >> n;
    vector<ll> neko(n);
    for(int i=0;i<n;++i) cin >> neko[i];
    ll l = 0,r=LONG_MAX;

    while(l<r)
    {
        mid = (l+r)/2;
        bool can = true;
        vector<ll> v;
        for(auto it : neko) if(it>mid) v.push_back(it);

        for(int i=0;i<v.size();i+=2)
        {
            if(v[i] != v[i+1])
            {
                can = false;
                break;
            }
        }

        if(can) r = mid;
        else l = mid+1;
    }

    cout << l;
}
