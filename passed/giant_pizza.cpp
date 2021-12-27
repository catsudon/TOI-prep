#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e5+9;
vector<int> v[2*MXN+1];
vector<int> rv[2*MXN+1];
int vst[2*MXN+1];
stack<int> s;
int r=1;

int nope(int n)
{
    if(n>MXN) return n-MXN;
    return n+MXN;
}

int dfs1(int i)
{
    vst[i] = true;
    for(auto it : v[i]) if(!vst[it]) dfs1(it);
    s.push(i);
}

int dfs2(int i)
{
    vst[i]  = r;
    for(auto it : rv[i]) if(!vst[it]) dfs2(it);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;

    while(n--)
    {
        char o,p;
        int a,b;
        cin >> o >> a >> p >> b;
        if(o=='-') a+=MXN;
        if(p=='-') b+=MXN;

        v[nope(a)].push_back(b);
        v[nope(b)].push_back(a);
        rv[a].push_back(nope(b));
        rv[b].push_back(nope(a));
    }

    for(int i=1;i<=m;++i) if(!vst[i]) dfs1(i);
    for(int i=1;i<=MXN;++i) vst[i] = false;

    while(!s.empty())
    {
        int tp = s.top();
        s.pop();
        if(vst[tp]) continue;
        dfs2(tp);
        r++;
    }

    bool ok=true;
    for(int i=1;i<=n;++i)
    {
        if(vst[i] == vst[i+MXN]) ok = false;
        cout << "IMPOSSIBLE";
        return 0;
    }
   // for(int )


}
