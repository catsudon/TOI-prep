#include<bits/stdc++.h>
#define f first
#define s second
#define INF 1e8
using namespace std;
const int X = 2009;
using pii = pair<int,int>;
using ppp = pair<int,pii>;
vector<pii> v[X];
int dp[X][X]; // position :: hop count = minimum bias
int n,e,op,ed;
int vst[X]; // lastest time we walked on this cave
queue<ppp> q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> op >> ed >> e;

    memset(dp ,100000009,sizeof(dp));
    memset(vst,100000009,sizeof(vst));

    for(int i=0;i<e;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        v[a].emplace_back(c,b);
    }
    int l; cin >> l;

    q.push({op,{0,0}});
    while(!q.empty())
    {
        int pos = q.front().f;
        int hop = q.front().s.f;
        int sum = q.front().s.s;
        q.pop();
        if(dp[pos][hop] <= sum) continue;
        if(vst[pos] < sum) continue; // this is BFS so  /// hop is probably more than the last value we stored

        dp[pos][hop] = sum;
        vst[pos] = sum;
        hop++;
        for(auto it : v[pos]) q.push({it.s,{hop,sum+it.f}});
    }
    while(l--)
    {
        int w; cin >> w;
        int mn = INF;
        for(int i=1;i<=n;++i)
        {
            if(dp[ed][i]!=INF) mn = min(mn,dp[ed][i]+((i-1)*w));
        }
        cout << mn << " ";
    }

}
