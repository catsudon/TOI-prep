#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int parent[100009];
int findparent(int n)
{
    if(parent[n]==0) return n;

    else return parent[n] = findparent(parent[n]);
}

int main()
{
    int n; cin >> n;
    vector<int> tsuyosa(n+1);
    tsuyosa.push_back(0);
    for(int i=1;i<=n;++i) {
            int a;cin >> a;
            tsuyosa.push_back(a);
    }

    int edge_count; cin >> edge_count;
    vector<pair<int,pair<int,int>> > edge(edge_count+1);
    for(int i=1;i<=edge_count;++i)
    {
        int a,b,c;
        cin >> a >> b;
        c = tsuyosa[a]+tsuyosa[b];
        edge[i] = {c,{a,b}};
    }
    sort(edge.begin(),edge.end());
    cout << endl;
    int ans=0;
    for(int i=1;i<=edge_count;++i)
    {
        int w = edge[i].f;
        int a = edge[i].s.f;
        int b = edge[i].s.s;
        int u = findparent(a);
        int v = findparent(b);
        cout << a << "  " << b << " "  << u << " " << v << " " << w << endl;
        if(u!=v && !(u==v==0)) continue;
        parent[a] = b;
        ans+=w;

    }
    cout << ans;
}
