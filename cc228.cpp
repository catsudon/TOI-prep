#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
using ppp = pair<pii,bool>; /// consumed : city :: used
vector<pii> v[100009];
ll dp[100009][2];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,t;
    cin >> n >> m >> k >> t;
    for(int i=1;i<=n;++i) for(int j=0;j<2;++j) dp[i][j] = LONG_MAX;
    while(m--)
    {
        ll a,b,c; cin >> a >> b >> c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    priority_queue<ppp,vector<ppp>,greater<ppp> > pq;
    pq.push({{0,1},0});
    while(pq.size())
    {
        ll sum = pq.top().f.f;
        ll city = pq.top().f.s;
        bool used = pq.top().s;
        pq.pop();
        if(dp[city][used] <= sum or sum > t) continue;
        dp[city][used] = sum;
        if(city == n) break;

        for(auto it : v[city])
        {
            if(!used and it.f > k and sum+k < dp[it.s][1]) pq.push({{sum+k,it.s},1});
            if(sum+it.f < dp[it.s][used]) pq.push({{sum+it.f,it.s},used});
        }
    }
    ll chg = min(dp[n][0],dp[n][1]);
    if(chg == LONG_MAX) cout << "No Honey TT";
    else
    {
        cout << "Happy Winnie the Pooh :3\n";
        cout << chg;
    }
}
