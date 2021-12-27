#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int32_t main()
{
    int n; cin >> n;
    ll gcm;
    cin >> gcm;
    ll sum = gcm;
    for(int i=1;i<n;++i)
    {
        ll a; cin >> a;
        gcm = __gcd(gcm,a);
        sum+=a;
    }

    cout << sum/gcm;
}
