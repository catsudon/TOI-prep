#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
int n,m,a,b,c,op,ed,mx=0;
vector<pii> v[2000];
int dp[2000][2000]; // time : node

int main()
{
    cin >> n >> m >> op >> ed;

    for(int i=0;i<m;++i)
    {
        cin >> a >> b >> c;
      //  c--;
        v[a].emplace_back(c,b);
        v[b].emplace_back(c,a);
    }

    memset(dp,-1,sizeof(dp));
    dp[op][0] = 0;
    for(int time=0;time<n;++time)
    {
        for(int node=1;node<=n;++node)
        {
            if(dp[node][time] == -1) continue;
            for(auto it : v[node])
            {
                int cost = it.f; //
                int dest = it.s; //

                dp[dest][time+1] = max(dp[dest][time+1] , dp[node][time] + cost);

                if(dest == ed) mx = max(mx,dp[ed][time+1]);
            }
        }
    }

    cout << mx;
}
