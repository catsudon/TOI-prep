#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pib = pair<int,bool>;
using ppp = pair<pib,int>; /// idx : minus or plus :: order
vector<bool> ok(500009,1);
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,m; cin >> n >> k >> m;
    vector<ppp> v;
    for(int i=1;i<=n;++i)
    {
        int a,b; cin >> a >> b;
        v.push_back({{a,1},i});
        v.push_back({{b+1,0},i});
    }

    sort(v.begin(),v.end());

    int ima = 0;
    for(auto it : v)
    {
        int idx = it.f.f;
        bool riru = it.f.s;
        int order = it.s;
        if(riru == 1)
        {
            if(ima < k) ima++;
            else ok[order] = 0;
        }
        else
        {
            if(ok[order]) ima--;
        }
    }
    while(m--)
    {
        int a; cin >> a;
        ok[a] ? cout << "Y " : cout << "N ";
    }
}
