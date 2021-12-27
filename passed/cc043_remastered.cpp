#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ppp = pair<int,pii>;
const int N = 309;
const int K = 2009;
vector<ppp> v[309]; // destination  ::  happiness : timewasted
int dp[N][K];
bool join[N][K];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,op,ed;
    cin >> n >> m >> k >> op >> ed;

    while(m--)
    {
        int a,b,c,d; cin >> a >> b >> c >> d;
        v[a].push_back({b,{c,d}});
        v[b].push_back({a,{c,d}});
    }

    join[op][0] = 1;
    for(int t =  0 ; t <= k ; ++t )
    {
        for(int city = 1 ; city <=n ; ++city )
        {
            if(!join[city][t]) continue;
            for(auto it : v[city])
            {
                int des = it.f;
                int hap = it.s.f;
                int cst = it.s.s;
                if(t+cst > k) continue;
                if(dp[des][t+cst] >= dp[city][t]+hap) continue;
                dp[des][t+cst] = dp[city][t]+hap;
                join[des][t+cst]=1;
        //        cerr << "new valid move " << des << ' ' << t+cst << endl;
            }
        }
    }

    int mx=0;
    for(int i=0;i<=k;++i) mx=max(mx,dp[ed][i]);
    if(mx==0)cout << "Impossible";
    else cout << mx;



}
