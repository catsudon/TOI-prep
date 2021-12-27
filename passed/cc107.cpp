#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll qs[1000009];
ll kadane[1000009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k ; cin >> n >> k;
    for(int i=1;i<=n;++i)
    {
        cin >> qs[i];
        qs[i]+=qs[i-1];
    }

    ll rrrr = 0;
    for(int i=1;i<=n;++i)
    {
        if(rrrr + qs[i]-qs[i-1] <= 0 ) rrrr = 0;
        else rrrr += qs[i]-qs[i-1];

        kadane[i] = rrrr;
    }

    ll mx = LONG_MIN;
    for(int i=k;i<=n;++i)
    {
        mx = max(mx , qs[i]-qs[i-k] + kadane[i-k]);
    }
    cout << mx;

}
