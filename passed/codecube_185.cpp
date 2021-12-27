#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
using ppp = pair<ll,pii>;
ll n,m,t,op,ed;
priority_queue<ppp,vector<ppp>,greater<ppp> > pq; // cost :: pos
bool vst[10009][10];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> t >> op >> ed;

    vector<pii> v[n+1]; // cost : destination
    while(m--)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        v[a].emplace_back(c,b);
    }

    pq.push({0,{0,op}}); // sum :: round : pos

    while(!pq.empty())
    {
        ll sum = pq.top().f;      // sum
        ll F = pq.top().s.f; F++;// round
        ll S = pq.top().s.s;    // now
        pq.pop();

        if(vst[S][F%t]) continue;
        vst[S][F%t] = true;

        if(F!=0 and F%t == 0 and S == ed) {cout << sum; return 0;}

        for(auto it : v[S]) pq.push({it.f+sum,{F,it.s}});
    }

    cout << -1;
}
