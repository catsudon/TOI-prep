#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int sze = 1000009;

vector<pll> v[sze]; /// cost : pos
bool vst[sze],tVst[sze];
ll sum=0,mx = 0,ans=0;
vector<ll> memo ; ll n;

int dfs(ll pos , ll sum)
{
    tVst[pos]=1;

    mx = max(mx,sum);

    for(auto it : v[pos])
    {
        if(tVst[it.s]) continue;
        dfs(it.s,it.f+sum);
    }

    tVst[pos]=0;

}

int fndB(ll pos, ll sum)
{
    vst[pos]=1;
    tVst[pos]=1;

    if(sum > mx)
    {
        mx = sum;
        memo = {pos};
    }
    else if(sum==mx) memo.emplace_back(pos);

    for(auto it : v[pos])
    {
        if(tVst[it.s]) continue;
        fndB(it.s,it.f+sum);
    }

    tVst[pos]=0;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        ll a,b; cin >> a >> b;
        v[i].push_back({b,a});
        v[a].push_back({b,i});
    }


    // since there are N nodes and N edges and every node must have at least 1 edges connected to it
    // therefore we can't have more than 1 cycle in each component


    // idea from IOI editorial
    // start at any random node (A) in the component
    // dfs to the farthest node from A (will call that B)
    // dfs from B to the farthest node C

    for(ll i=1;i<=n;++i)
    {
        if(vst[i]) continue;
        mx=-1 , memo.clear();
        fndB(i,0);

     //   cerr << mx << ' ' << memo ;
        ll temp = mx;
        mx = 0;
        for(auto haha : memo)
            dfs(haha,0);
    //    cerr << ' ' << mx << endl;



        ans+=max(temp,mx);

    }

    cout << ans;


}
