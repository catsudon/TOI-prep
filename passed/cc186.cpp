#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = int;
using pll = pair<ll,ll>;
vector<pll> v[100009];
int dis[100009];
int vst[100009];

int dfs(int i ,int x)
{
    dis[i] = x;
    vst[i] = 1;
    for(auto it : v[i])
    {
        if(vst[it.s]) continue;
        dfs(it.s,it.f^x);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,k; cin >> n >> k;
n--;
    while(n--)
    {
        ll a,b,c; cin >> a >> b >> c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }

    dfs(1,0);
    while(k--)
    {
        int a,b; cin >> a >> b;
        int ans = dis[a] ^ dis[b];
        cout << ans << endl;
    }
}
