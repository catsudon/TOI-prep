#include<bits/stdc++.h>
using namespace std;
const int Z = 5e5+9;
vector<int> v[Z];
bool cycle[Z];
bool vst[Z];
int cnt[Z];
int parent[Z]; /// only put parent when found cycle
int op;
bool cyc;

int fnd_p(int n)
{
    if(parent[n]==0) return n;
    return parent[n] = fnd_p(parent[n]);
}

int merge(int n,int m)
{
    parent[fnd_p(n)] = fnd_p(m);
}

int dfs(int n,int p)
{
    if(cycle[n] or vst[n]) return 0;
    if(n==op)
    {
        cyc = true;
        return 0;
    }
    if(p!=op and fnd_p(n) != fnd_p(p)) merge(n,p);

    vst[n] =true;
    bool x = false;
    for(auto it : v[n])
    {
        if(it!=p and !vst[it])
        {
            cyc=false;
            dfs(it,n);
            if(cyc and p!=op)
            {
                cycle[fnd_p(n)] = true;
                x=true;
            }
        }
    }
    if(x) cyc=true;
    vst[n]=false;
}

int main()
{
    int n; cin >> n >> op;
    for(int i=0;i<n;++i)
    {
        int a,b; cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }

    for(auto it : v[op])
    {
        dfs(it,op);
    }
   // for(int i=1;i<=n;++i) cout << cycle[i] << " ";
    int mx=0;
    int memo = 0;
    cerr << "cycle : ";
    for(int i=1;i<=n;++i) if(cycle[i]) cerr << i << " ";
    cerr << endl;
    for(int i=1;i<=n;++i)
    {
        if(i==op or cycle[fnd_p(i)]) continue;
        cnt[fnd_p(i)]++;
        if(fnd_p(i) == 1) cerr << i << " ";
    }
    cerr << endl;
    cerr << fnd_p(10) << " " << cycle[fnd_p(10)] << endl;
    for(int i=1;i<=n;++i) if(i==op) continue; else if(cnt[i] > mx) {mx=cnt[i],memo=i;}
    cout << memo << endl << mx-1;
}
