#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define f first
#define s second
#define N 501
#define INF 1e7
vector<int> cnt(N,0);
vector<int> mndis(N,INF);


int main()
{
    queue<int> q; // we store index
    q.push(op);
    mndis[op] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cnt[u]++;
        if(cnt[u] > N)
        {
            /// found_neg_cycle;
        }
        for(auto it : v[u])
        {
            int v = it.s;
            int w = it.f;
            if(mndis[u]+w < mndis[v]) { mndis[v] = mndis[u]+w; q.emplace(v); }
        }
    }
}
