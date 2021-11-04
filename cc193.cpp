#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

pll a[100009];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,k; cin >> n >> k;
    ll mx = 0;
    priority_queue<pll> pq;
    for(int i=1;i<=n;++i) cin >> a[i].f >> a[i].s;
    sort(a+1,a+n+1);

    for(int i=1;i<=n;++i)
    {
        ll pos,val;
        pos = a[i].f;
        val = a[i].s;
        cin >> pos >> val;
        while(pq.size() and pos - pq.top().s > k) pq.pop();

        ll tempMx = mx;
        if(pq.size())
        {
            mx = max(mx,val-pos+pq.top().f);
       //     pq.push({val-pos+pq.top().f,pos});
        }
        pq.push({val+pos+tempMx,pos}); // didn't matched
    }

    cout << mx;
}
