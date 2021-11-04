#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int sze = 1e6+9;
int n;
vector<pll> v[sze]; /// cost : pos
bool vst[sze],tVst[sze];
ll rr[sze]; /// maximum of fp(i)
int p[sze];
ll sum=0,mx = 0,ans=0;


int fp(ll i)
{
    if(p[i] == 0 ) return i;
    return p[i] = fp(p[i]);
}

void dfs(int pos,ll sum)
{
    if(tVst[pos]) return ;
    vst[pos] = 1;
    tVst[pos] = 1;
    mx = max(mx,sum);
    for(auto it : v[pos])
    {
        if(tVst[it.s]) continue;
        dfs(it.s,sum+it.f);
    }

    tVst[pos] = 0;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    set<pair<ll,pll> > e; /// -cost ::  u:v
    for(int i=1;i<=n;++i)
    {
        ll a,b; cin >> a >> b;
        v[i].push_back({b,a});
        v[a].push_back({b,i});
        e.insert({-b,{i,a}});
    }

    /// disjoint
    for(auto it : e)
    {
        ll cst = -it.f;
        ll u = it.s.f;
        ll v = it.s.s;
        if(fp(u) == fp(v)) continue;
      //  cerr << u << " linked w " << v << " consumed " << cst << endl;
        p[fp(u)] = fp(v);
    }

    /// dfs
    for(int i=n;i>=1;--i)
    {
     //   if(vst[i]) continue;
        for(int i=1;i<=n;++i) vst[i]=0,tVst[i]=0;
        mx=0; dfs(i,0);
        rr[fp(i)] = max(rr[fp(i)],mx);
    //    cerr << mx << " w " << fp(i) << " | ";
    }
    for(int i=1;i<=n;++i) ans+=rr[i];
 //   cerr << endl;
    cout << ans;
}
