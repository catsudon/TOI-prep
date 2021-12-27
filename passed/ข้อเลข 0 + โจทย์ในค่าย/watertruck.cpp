#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
vector<pair<pii,int> > v[50009]; // dis/node , roadnum
int vst[100009];
int mn = INT_MAX;
int start(int coor,int sum)
{
    if(sum>mn) return 0;
    queue<pair<pii,int> > q;
    for(auto it : v[coor])
    {
        if(vst[it.s]==0) q.push({{it.f.f,it.f.s},it.s});
    }
    if(q.empty())
    {
        for(auto it : v[coor])
        {
            if(vst[it.s]==1) q.push({{it.f.f,it.f.s},it.s});
        }
    }
    if(q.empty())
    {
        if(coor==0)
        {
            if(sum<mn) mn=sum;
        }
        return 0;
    }
    while(!q.empty())
    {
        int F = q.front().f.f; // distance
        int S = q.front().f.s; // node
        int roadn = q.front().s;
        q.pop();
        if(vst[roadn]==2) continue;
        vst[roadn]++;
        start(S,sum+F);
        vst[roadn]--;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int e,n; cin >> e >> n;
    for(int i=0;i<e;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        v[a].push_back({{c,b},i});
        v[b].push_back({{c,a},i});
    }
    start(0,0);
    cout << mn;
}
