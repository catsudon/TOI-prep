#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ppp = pair<int,pii>; // sum , climbed : node
const int N = 100009;
const int INF = INT_MAX;
int dp[N][6]; // node : climbed down
vector<pii> v[N]; // cost : node_v

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin >> n >> m >> k;
    for(int i=1;i<=m;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        v[a].emplace_back(c,b);
    }
    for(int i=0;i<=n;++i) for(int j=0;j<=5;++j) dp[i][j] = INF;
    priority_queue<ppp,vector<ppp>,greater<ppp> > pq; // sum : climbed_down , node
    pq.push({0,{0,1}});
    while(pq.size())
    {
        int sum = pq.top().f;
        int climbed = pq.top().s.f;
        int pos = pq.top().s.s;
        pq.pop();
        if(climbed > k ) continue;
        if(dp[pos][climbed] <= sum ) continue;
        dp[pos][climbed] = sum;
     //   cerr << sum << " "  << climbed << " " << pos << "\n" ;
        if(pos == n ) continue;
        for(auto it : v[pos])
        {
            int node_v = it.s;
            int cost = it.f;
            int cb = climbed;
            if(cost < -100)
            {
                cb++;
                if(cb > k) continue;
                if(dp[node_v][cb] <= sum ) continue;
                pq.push({sum,{cb,node_v}});
            }
            else if(cost <= 0)
            {
                if(cb > k) continue;
                if(dp[node_v][cb] <= sum ) continue;
                pq.push({sum,{cb,node_v}});
            }
            else
            {
                if(cb > k) continue;
                if(dp[node_v][cb] <= sum ) continue;
                pq.push({sum+cost,{cb,node_v}});
            }
        }
    }
    int mn = INF;
    for(int i=0;i<=k;++i) mn = min(mn,dp[n][i]);
    if(mn==INF) cout << -1;
    else cout << mn;

}
