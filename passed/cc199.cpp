#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
int parent[100009];
bool vst[100009];
int f_pa(int i)
{
    if(parent[i] == 0 )return i;
    return parent[i] = f_pa(parent[i]);
}

int merge(int i,int j)
{
    parent[f_pa(i)] = f_pa(j);
}

int main()
{
    int n,m; cin >> n >> m;
    vector<pair<pii,pii> > v; /// cost : n1 :: n2 :: cmdnum
    for(int i=1;i<=m;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        v.push_back({{-c,a},{b,i}});
    }
    sort(v.begin(),v.end());
    long long sum=0;
    set<int> cmd;
    for(int i=0;i<m;++i)
    {
        int F = v[i].f.s;
        int S = v[i].s.f;
        int cmdnum = v[i].s.s;
        int cost = -v[i].f.f;
        if(f_pa(F) == f_pa(S)) continue;
        sum+=(long long) cost;
        cmd.insert(cmdnum); vst[cmdnum]=1;
        merge(F,S);
    }
    for(int i=0;i<m;++i)
    {
        int cmdnum = v[i].s.s;
        int cost = -v[i].f.f;
        if(vst[cmdnum]) continue;
        sum+=cost;
        cmd.insert(cmdnum);
        break;
    }
    int T; cin >> T;
    if(cmd.size() == n) cout << sum;
    else
    {
        cout << -1; return 0;
    }
    if(T==2)
    {
        cout << endl;
        for(auto it : cmd) cout << it << " ";
    }

}
