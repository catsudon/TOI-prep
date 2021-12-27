#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ppp = pair<int,pii>; // destination :: happiness : time
int n,m,lim;
int op,ed;
int dp[301][2001]; // city : time
vector<ppp> v[301];
int mx = -1;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> lim >> op >> ed;
    for(int i=0;i<=n;++i) for(int j=0;j<=lim;++j) dp[i][j] = -1;
    for(int i=0;i<m;++i)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        v[a].push_back({b,{c,d}});
        v[b].push_back({a,{c,d}});
    }
    // simulate from every [time] and [node]
    dp[op][0] = 0;
    for(int time=0;time<=lim;++time)
    {
        for(int node=1;node<=n;++node)
        {
            if(dp[node][time] == -1) continue; // illegal path
            for(auto it : v[node])
            {
                int des = it.f;
                int happ = it.s.f;
                int consume = it.s.s;
                if(consume + time > lim) continue;
                dp[des][consume + time] = max(dp[node][time]+happ,dp[des][consume+time]); // become legal path (lol)
                if(des==ed) mx=max(mx,dp[des][consume+time]);
            }
        }
    }

  //  for(int i=0;i<=n;++i)
    //{
      //  for(int j=0;j<=lim;++j) cerr << dp[i][j] << " ";
        //cerr << endl;
    //}


    if(mx==-1) cout << "Impossible";
    else cout << mx;
}
