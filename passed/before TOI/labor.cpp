#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    ll n,pkg; cin >> n >> pkg;
    ll power[n+9];
    for(int i=0;i<n;++i) cin >> power[i];

    ll l = 0 , r = 1e15;

    while(l<=r)
    {
        ll mid = (l+r)/2;
        ll sum = 0;
        for(int i=0;i<n;++i) sum+= mid/power[i];

        if(sum >= pkg) r=mid-1;
        else l=mid+1;
    }

    cout << l;
}
