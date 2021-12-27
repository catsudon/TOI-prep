#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ppp = pair<int,pii>;
using ll = long long;
int tsuyoiiii[1000001];
int parent[1000001];
ll ans;

int find(int num)
{
    if(parent[num]==0) return num;

    return parent[num] = find(parent[num]);
}

int merge(int a,int b)
{
    parent[find(a)] = find(b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;++i) cin >> tsuyoiiii[i];

    int m; cin >> m;
    vector<ppp> edges(m);
    for(int i=0;i<m;++i)
    {
        int a,b;
        cin >> a >> b;
        edges[i] = {tsuyoiiii[a]+tsuyoiiii[b],{a,b}};
    }

    sort(edges.begin(),edges.end());

    for(auto it : edges)
    {
        int tsuyosa = it.f;
        int F = it.s.f;
        int S = it.s.s;

        if(find(F) == find(S)) continue;
       // cerr << tsuyosa << " " << F << " " << S << endl;
        ans+=tsuyosa;
        merge(F,S);
    }


    cout << ans;



}
