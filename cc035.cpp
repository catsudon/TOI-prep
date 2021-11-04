#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
vector<int> dp(100009,INT_MAX);
vector<int> v[100009];
ll val[100009];
vector<ll> dp2(100009,INT_MIN);
ll sum=0;
int main()
{
    int n,e,op;
    cin >> n >> e >> op;
    for(int i=1;i<=n;++i) cin >> val[i];
    while(e--)
    {
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<pair<int,int> > q;
    q.push({op,0});
    while(q.size())
    {
        int F = q.front().f; /// position
        int S = q.front().s; /// cnt
        q.pop();
        if(dp[F] <= S) continue;
        dp[F] = S;
        dp2[S] = max(dp2[S],val[F]);
        for(auto it : v[F]) q.push({it,S+1});
    }
    for(int i=1;i<=n;++i)
        if(dp2[i] == INT_MIN) continue;
        else
        sum+=dp2[i],cerr << dp2[i] << " "; cerr << endl;

    cout << sum;

}
