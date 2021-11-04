#include<bits/stdc++.h>
using namespace std;
int n,e;
string a; bool cycle = 0;
vector<int> adj[300009];
int vst[300009]; /// 0 = nonvst : 1 = vsting : 2 = vsted
int dp[300009][29]; /// node : alp --> alpcnt
int h[30];
void cyc(int i)
{
    if(cycle) return ;
    vst[i] = 1;
    for(auto it : adj[i])
    {
        if(vst[it]==2) continue;
        if(vst[it]==1)
        {
            cycle=true; break;
        }
        else cyc(it);
    }

    vst[i] = 2;
}

void dfs(int u)
{
    if(vst[u]) return ;
    vst[u] = 1;
    for(auto v : adj[u])
    {
        if(!vst[v]) {dfs(v);}
        for(int i=0;i<26;++i) dp[u][i] = max(dp[u][i],dp[v][i]);
    }
    dp[u][a[u]-'a']++;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> e >> a;
    a=" "+a;

    while(e--)
    {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
    }

    /// find cyc

    for(int i=1;i<=n and !cycle;++i)
    {
        if(vst[i]) continue;
        cyc(i);
    }

    if(cycle) {cout << -1; return 0;}

    /// do dfs
    int ans = 0;
    for(int i=1;i<=n;++i) vst[i] = 0;
    for(int i=1;i<=n;++i)
    {
        if(vst[i]) continue;
        memset(h,0,sizeof(h));
        dfs(i); for(int j=0;j<26;++j)ans = max(ans,dp[i][j]);
    }

    cout << ans;
}
