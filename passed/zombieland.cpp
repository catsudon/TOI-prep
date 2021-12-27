#include<bits/stdc++.h>
#define f first
#define s second
const int sze = 2e5+9;
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
vector<pll> v[sze];
bool infected[sze];
ll dp[sze];
ll verse1[sze],verse2[sze];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,e,op,ed; cin >> n >> e >> op >> ed;
    while(e--)
    {
        ll a,b,c; cin >> a >> b >> c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    for(int i=0;i<=n;++i) dp[i] = LONG_MAX,verse1[i] = LONG_MAX,verse2[i] = LONG_MAX;

    priority_queue<pll,vector<pll>,greater<pll> > pq;
    pq.push({0,op});
    while(pq.size())
    {
        ll F = pq.top().f;
        ll S = pq.top().s;
        pq.pop();
        if(F >= verse1[S]) continue;
        verse1[S] = F;

        for(auto it : v[S]) pq.push({F+it.f,it.s});
    }

    ll minimum_cost = verse1[ed];

    pq.push({0,ed});
    while(pq.size())
    {
        ll F = pq.top().f;
        ll S = pq.top().s;
        pq.pop();
        if(F >= verse2[S]) continue;
        verse2[S] = F;

        for(auto it : v[S]) pq.push({F+it.f,it.s});
    }

    for(int i=1;i<=n;++i) if(verse1[i]+verse2[i] == minimum_cost) pq.push({0,i}),cerr << i << " "; cerr << endl;
    while(pq.size())
    {
        ll F = pq.top().f;
        ll S = pq.top().s;
        pq.pop();
        if(dp[S] <= F) continue;
        dp[S] = F;

        for(auto it : v[S]) pq.push({F+it.f,it.s});
    }

    ll q; cin >> q;
    while(q--)
    {
        ll l; cin >> l;
        cout << dp[l] << endl;
    }



}
