#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
vector<pii> v[2001];
int dp[2001][2001]; /// pos : hop
int vst[2001];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp ,100000009,sizeof(dp));
    memset(vst,100000009,sizeof(vst));
    int n,op,ed,e; cin >> n >> op >> ed >> e;
    for(int i=0;i<e;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        v[a].emplace_back(c,b);
    }

    queue<pair<pii,int> > q; /// position , sum :: hop
    q.push({{op,0},0});

    while(!q.empty())
    {
        int pos = q.front().f.f;
        int sum = q.front().f.s;
        int hop = q.front().s;
        q.pop();

        if(dp[pos][hop] <= sum) continue;
        if(vst[pos] <= sum) continue; // found cycle
        dp[pos][hop] = sum;
        vst[pos] = sum;
        hop++;
        for(auto it : v[pos]) q.push({{it.s,sum+it.f},hop});
    }

    int l;cin >> l;
    while(l--)
    {
        int w;cin >> w;
        long long mn = 2200000000;
        for(int i=1;i<=n;++i)
        {
            if(dp[ed][i]!=100000009) mn = min(mn,(long long)dp[ed][i]+w*(i-1));
        }
        cout << mn << " ";
    }


}
