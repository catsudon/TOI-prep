#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
ll dp[2009][2009]; // node : hop => sum    [min]
ll cyc_detect[2009];
vector<pair<ll,int> > v[2009]; // cost : node
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,op,ed,e,l;
    cin >> n >> op >> ed >> e;
    while(e--)
    {
        int a,b; ll c; cin >> a >> b >> c;
        v[a].emplace_back(c,b);
    }
    cin >> l;
    for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) dp[i][j] = LONG_MAX;
    for(int i=0;i<=n;++i) cyc_detect[i] = LONG_MAX;
    queue<pair<ll,pair<int,int> > > q; // sum :: pos : hop
    q.push({0,{op,0}});
    while(q.size())
    {
        ll sum = q.front().f;
        int pos = q.front().s.f;
        int hop = q.front().s.s;
     //   cerr << " < < " << pos << " " << hop << endl;
        q.pop();
        if(cyc_detect[pos] <= sum) continue; /// cyc
        if(dp[pos][hop] <= pos) continue;
        cyc_detect[pos] = sum;
        dp[pos][hop] = sum;
        for(auto it : v[pos])
        {
            q.push({it.f+sum,{it.s,hop+1}});
        }

    }
    while(l--)
    {
        int w; cin >> w;
        ll mn = LONG_MAX;
        for(int i=1;i<=n;++i)
        {
            if(dp[ed][i]!=LONG_MAX) mn = min(mn,dp[ed][i]+((i-1)*w));
        }
        cout << mn << " ";
    }


}
