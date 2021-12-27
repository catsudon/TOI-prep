#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ppp = pair<int,pii>;
int n,t;
vector<ppp> e;
int a[309][309];
int p[309];
int deg[309];

int fp(int i)
{
    if(p[i]==0) return i;
    return fp(p[i]);
}

int merge(int i,int j)
{
    p[fp(j)] = fp(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> t;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin >> a[i][j];
            if(i>=j) continue;
            e.push_back({a[i][j],{i,j}});
        }
    }
    sort(e.begin(),e.end());
    int mx=-1,mem=0;
    for(auto it : e)
    {
        if(fp(it.s.f) == fp(it.s.s)) continue;
        merge(it.s.f,it.s.s);
        deg[it.s.s]++ , deg[it.s.f]++;
    }
    for(int i=1;i<=n;++i)// cerr << deg[i] << " ";
    {
        if(deg[i]<=mx) continue;
        mx = deg[i],mem=i;
    }
    cout << mem;
    if(t==2) cout << endl << mx;
}
