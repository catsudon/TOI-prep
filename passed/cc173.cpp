#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ppp = pair<int,pii>;

int v[100009];
bool vst[100009];

vector<int> adj[100009];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,e; cin >> n >> e;
    for(int i=1;i<=n;++i) cin >> v[i];
    while(e--)
    {
        int a,b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    int ans = 0;
    priority_queue<pii> pq; // sum  : pos
    pq.push({0,1});

    while(pq.size())
    {
        int cst = pq.top().f;
        int pos = pq.top().s;
        pq.pop();

        if(vst[pos]) continue;
        vst[pos]=1;
        ans += cst;

        for(auto it : adj[pos])
        {
            if(vst[it]) continue;
            pq.push({v[it]+v[pos],it});
        }

    }

    cout << ans;

}
