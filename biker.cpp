#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using ppp = pair<pii,pii>;
vector<pair<pii,int> > v[50009];
bool markEdge[70009];
bool vst[50009];
bool ok;
int target,Eidx;

map<int,int> mp;

int dfs(int pos,int p)
{
    if(vst[pos]) return 0;
    if(ok) return 0;
    vst[pos]=1;
    for(auto it : v[pos])
    {
        if(markEdge[it.s] or it.f.s==p) continue;
        if(it.f.s == target) ok = 1;
        dfs(it.f.s,pos);
    }
    vst[pos]=0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,m; cin >> n >> m;
    vector<ppp> edges; // cost : idx  :: u : v
    for(int i=1;i<=n;++i)
    {
        int a; cin >> a;
        mp[a] = i;
    }
    for(int i=1;i<=m;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        a=mp[a];
        b=mp[b];
        v[a].push_back({{c,b},i});
        v[b].push_back({{c,a},i});
        edges.push_back({{c,i},{a,b}});
    }
    sort(edges.begin(),edges.end());

    ll sum = 0;
    for(auto it : edges)
    {
        int cost = it.f.f;
        int idx  = it.f.s;
        int node_u = it.s.f;
        int node_v = it.s.s;

        ok = 0;
        target = node_v; Eidx = idx;

        dfs(node_u,node_v);

        if(ok) markEdge[idx]=1,sum+=cost;
    }

    cout << sum;
}
