#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
long long sum=0;

int main()
{
    int n,q; cin >> n >> q;
    int adj[n+1][n+1];
    vector<bool> vst(n+1,false);
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) adj[i][j] = q;
    for(int i=1;i<n;++i)
    {
        int a,b,c ; cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
    }

    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,n});
    while(pq.size())
    {
        int F = pq.top().f;
        int S = pq.top().s;
        pq.pop();
        if(vst[S]) continue;
        vst[S] = true;

        sum+=F;
        for(int i=1;i<=n;++i)
        {
            if(vst[i]) continue;
            pq.push({adj[i][S],i});
        }
    }

    cout << sum;

}
