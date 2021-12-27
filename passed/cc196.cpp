#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using ppp = pair<ll,int>; // sum : pos
vector<pii> v[100009];
ll op[100009];
ll ed[100009];
ll dp[100009];
bool palace[100009];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    while(m--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }

    int A,B,C,D; cin >> A >> B >> C >> D;
    for(int i=1;i<=100000;++i) op[i] = LONG_MAX , ed[i] = LONG_MAX , dp[i] = LONG_MAX;

    // from A to everywhere
    priority_queue<ppp,vector<ppp>,greater<ppp> > pq;
    pq.push({0,A});
    while(pq.size())
    {
        ll sum = pq.top().f;
        ll pos = pq.top().s;
        pq.pop();

        if(op[pos] <= sum) continue;
        op[pos] = sum;

        for(auto it : v[pos])
        {
            int cost = it.f;
            int nv = it.s;
            if(op[nv] <= (ll)cost+sum) continue;
            pq.push({(ll)cost+sum,nv});
        }
    }

    // from B to everywhere
    pq.push({0,B});
    while(pq.size())
    {
        ll sum = pq.top().f;
        ll pos = pq.top().s;
        pq.pop();

        if(ed[pos] <= sum) continue;
        ed[pos] = sum;

        for(auto it : v[pos])
        {
            int cost = it.f;
            int nv = it.s;
            if(ed[nv] <= (ll)cost+sum) continue;
            pq.push({(ll)cost+sum,nv});
        }
    }

    for(int i=1;i<=n;++i)
    {
        if(op[i] + ed[i] == op[B]) palace[i] = 1;
    }

    pq.push({0,C});
    while(pq.size())
    {
        ll sum = pq.top().f;
        int pos = pq.top().s;
        pq.pop();

        if(palace[pos]) continue;
        if(dp[pos] <= sum) continue;
        dp[pos] = sum;

        for(auto it : v[pos])
        {
            int cost = it.f;
            int nv = it.s;
            if(palace[nv]) continue;
            if(dp[nv] <= (ll)cost+sum) continue;
            pq.push({(ll)cost+sum,nv});
        }
    }

  //  for(int i=1;i<=n;++i) cerr << op[i] << " "; cerr << endl;
  //  for(int i=1;i<=n;++i) cerr << ed[i] << " "; cerr << endl;
  //  for(int i=1;i<=n;++i) cerr << dp[i] << " "; cerr << endl;

    if(dp[D] == LONG_MAX) cout << -1;
    else cout << dp[D];

}
