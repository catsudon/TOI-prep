#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
const int MXN = 200009;
stack<int> s;
vector<int> vst(MXN);
vector<int> v[MXN];
vector<int> rev[MXN];
int r,A=5;
int shigeo(int i) // use Shigeo Tokuda's algorithm
{
    if(vst[i]) return 0;
    vst[i] = 1;
    for(auto it : v[i]) if(!vst[it]) shigeo(it);
    s.push(i);
}
int shigeo2(int i) // use Shigeo Tokuda's algorithm
{
    if(vst[i]) return 0;
    vst[i] = r;
    for(auto it : rev[i]) if(!vst[it]) shigeo2(it);
}





int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
while(A--)
{
    int n,m; cin >> n >> m ;
    pii way[MXN];
    int nope[MXN];

    for(int i=0;i<n;++i)
    {
        int a,b; cin >> a >> b;
        way[i] = {a,b};
    }

    for(int i=1;i<=m/2;++i)
    {
        int a,b; cin >> a >> b;
        nope[a] = b;
        nope[b] = a;
    }
    for(int i=1;i<=m;++i) {v[i].clear();rev[i].clear();}
    for(int i=0;i<n;++i)
    {
        int a = way[i].f, b = way[i].s;
        v[nope[a]].emplace_back(b);
        v[nope[b]].emplace_back(a);
        rev[b].emplace_back(nope[a]);
        rev[a].emplace_back(nope[b]);
    }
    vst.assign(MXN,0);
    for(int i=1;i<=m;++i) if(!vst[i]) shigeo(i);
    vst.assign(MXN,0);
    r=1;
    while(!s.empty())
    {
        int i = s.top();
        s.pop();
        if(!vst[i]) shigeo2(i);
        r++;
    }
    int ok = true;
    for(int i=1;i<=m;++i) if(vst[i] == vst[nope[i]]) {ok = false; break;}
    !ok ? cout << "N" : cout << "Y";
}
}
