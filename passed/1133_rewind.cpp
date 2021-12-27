#include<bits/stdc++.h>
#define INF 1e8+8
using namespace std;
vector<int> station[1000009];
int adj[501][501];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;++i)
    {
        int a,b; cin >> a;
        for(int j=0;j<a;++j)
        {
            cin >> b;
            station[b].push_back(i);
        }
        for(int j=1;j<=m;++j) adj[i][j]=INF;
    }
    for(int k=1;k<=n;++k)
    for(auto it : station[k])
    {
        for(auto ti : station[k])
        {
            if(it==ti)adj[it][ti] = 0;
            else adj[it][ti] = 1;
        }
    }


    for(int k=1;k<=m;++k)
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=m;++j)
        {
            {
                adj[i][j] = min(adj[i][j] , min(adj[k][j],adj[j][k])+min(adj[i][k],adj[k][i]));
            }
        }
    }
    int q; cin >> q;
    for(int i=0;i<q;++i)
    {
        int a,b; cin >> a >> b;
        int ans = INF;
        for(auto it : station[a])
            for(auto ti : station[b])
        {
            ans = min(ans,adj[ti][it]);
        }
        if(ans==INF) cout << "impossible\n"; else cout << ans << "\n";
    }
}
