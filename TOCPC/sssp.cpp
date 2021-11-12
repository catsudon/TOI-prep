#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = int;
using pll = pair<ll,ll>;
vector<ll> dp(100009,INT_MAX);
vector<pair<ll,ll> > v[100009];
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie();
    int n,m; cin >> n >> m;
    while(m--)
    {
        ll a,b,c ; cin >> a >> b >> c;
        v[a].emplace_back(c,b);
        v[b].emplace_back(c,a);
    }
    priority_queue<pll,vector<pll>,greater<pll> > pq;
    pq.push({0,1});

    while(pq.size())
    {
        ll sum = pq.top().f;
        ll pos = pq.top().s;
        pq.pop();

        if(dp[pos] != INT_MAX) continue;
        dp[pos] = sum;

        for(auto it : v[pos])
        if(dp[it.s] == INT_MAX) pq.push({it.f+sum,it.s});


    }

    for(int i=1;i<=n;++i) cout << dp[i] << ' ';
}
