#include<bits/stdc++.h>
#define f first
#define s second
#define INF INT_MAX
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ppp = pair<pii,pib>;
bool vst[101][101][2];
int dp[101][101][2];
int cost[101];
int n,op,ed,lim,m;
vector<pii> v[101];

int main()
{
    cin >> n;
    for(int i=1;i<=n;++i) cin >> cost[i];
    cin >> op >> ed >> lim >> m;

    for(int i=0;i<101;++i) for(int j=0;j<101;++j) for(int k=0;k<2;++k) dp[i][j][k] = INF;
    for(int i=0;i<m;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        v[a].emplace_back(c,b);
        v[b].emplace_back(c,a);
    }

    priority_queue<ppp,vector<ppp>,greater<ppp> > pq; // sum : fuel :: city : used
    pq.push({{0,0},{op,false}});

    int ans = INF;

    while(!pq.empty())
    {
        int sum = pq.top().f.f;
        int fuel = pq.top().f.s;
        int city = pq.top().s.f;
        bool used = pq.top().s.s;
        pq.pop();

        if(city==ed)
        {
            if(!used) ans = min(ans,sum);
            else
            {
                ans = min(ans,sum+(lim-fuel)*cost[city]);
            }
        }

        if(vst[city][fuel][used]) continue;
        vst[city][fuel][used] = true;

        for(auto it:v[city])
        {
            if(!used)
            {
                if(sum<dp[it.s][fuel][used])
                {
                    dp[it.s][fuel][used] = sum;
                    pq.push({{sum,lim-it.f},{it.s,true}});
                }
            }

            for(int j=0;j+fuel<=lim;++j)
            {
                if(j+fuel<it.f) continue;
                else if(sum+(j*cost[city]) < dp[it.s][j+fuel - it.f][used])
                {
                    dp[it.s][j+fuel - it.f][used] = sum+(j*cost[city]);
                    pq.push({{sum+(j*cost[city]),j+fuel-it.f},{it.s,used}});
                }
            }
        }
    }

    cout << ans;
}
