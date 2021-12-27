#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    while(q--)
    {
        ll n,sum=0; cin >> n;
        for(int i=0;i<n;++i)
        {
            ll a; cin >> a;
            sum+=a;
        }
        n*=n;
        n/=2;
        if(sum >= n) cout << "No\n";
        else cout << "Yes\n";

    }
}
