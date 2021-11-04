#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int q; cin >> q;
    for(int i=1;i<=q;++i)
    {
        int n,k; cin >> n >> k;
        ll mx=-1;
        while(n--)
        {
            ll a; cin >> a;
            a%=k;
            mx = max(mx,a);
        }
        cout << "Case #" << i << ": " << mx << endl;

    }
}
