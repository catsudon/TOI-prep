#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e5+1;
int n,k,t,tt=0,l=0;
vector<int> on_this_level_we_have[10009];
int topo[MXN],vst[MXN];
vector<int> v[MXN];

int dfs(int pos)
{
    if(vst[pos]==2 or tt>t) return 0;
   // cerr << pos << " " << tt << " " << mid << endl;;
    vst[pos] = 1; tt++;
    for(auto it : v[pos])
    {
        if(vst[it] == 0) dfs(it);
        else if(vst[it]==1) tt = 2e8;
    }
    vst[pos] = 2;
}
int main()
{
    cin >> n >> k >> t;
    for(int i=1;i<=n;++i)
    {
        int lv,q;cin >> lv >> q;
        topo[i] = q;
        on_this_level_we_have[lv].emplace_back(i);
        while(q--)
        {
            int t; cin >> t;
            v[i].emplace_back(t); // before dev [i] must dev [t]
        }
    }
    for(int i=1;i<=k;++i)
    {
        for(auto it : on_this_level_we_have[i])
        {
            if(!vst[it]) dfs(it);
        }
        if(tt > t) break;
        l=i;
    }

    l==0 ? cout << -1 : cout << l;
}
