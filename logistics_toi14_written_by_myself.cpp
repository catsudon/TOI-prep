#include<bits/stdc++.h>
#define f first
#define s second
#define  INF INT_MAX
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ppp = pair<pii,pib>;
priority_queue<ppp,vector<ppp>,greater<ppp> > pq; // sum / oil / city / used?
vector<pii> v[101];
int dp[101][101][2];
int vst[101][101][2]; // sum // oil // used
int cost[101];
int ans = INT_MAX;

int main()
{
    int n; cin >> n;
    for(int i=1;i<=n;++i) cin >> cost[i];
    int op,ed,lim,m;
    cin >> op >> ed >> lim >> m;
    for(int i=0;i<m;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        v[a].emplace_back(c,b);
        v[b].emplace_back(c,a);
    }
    for(int i=0;i<=100;++i)for(int j=0;j<=100;++j) for(int k=0;k<=1;++k) dp[i][j][k] = INT_MAX;

    pq.push({{0,0},{op,false}});

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
            else ans = min(ans,sum+((lim-fuel)*cost[city]));
        }

        if(vst[city][fuel][used]) continue;
        vst[city][fuel][used] = true;

     //   cerr << sum << " " << fuel << " " << city << " " << endl;

        for(auto it : v[city])
        {
            if(!used)
            {
                if(sum<dp[it.s][lim-it.f][true])
                {
                    dp[it.s][lim-it.f][true] = sum;
                    pq.push({{sum,lim-it.f},{it.s,true}});
                }
            }


            for(int j=0;j+fuel<=lim;++j)
            {
                if(j+fuel<it.f) continue;
                if(sum+(j*cost[city])<dp[it.s][j+fuel - it.f][used])
                {
                    dp[it.s][j+fuel-it.f][used] = sum+(j*cost[city]);
                    pq.push({{sum+(j*cost[city]),j+fuel-it.f},{it.s,used}});
                }
            }
        }



    }
    cout << ans;
}
