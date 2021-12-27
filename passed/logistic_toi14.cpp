#include<bits/stdc++.h>
#define f first
#define s second
#define INF 1e9
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ppp = pair<pii,pib>;
int cost[101];
bool vst[101][101][2]; // city : fuel : cardused?
int dis[101][101][2]; // city : fuel : cardused?
vector<pii> v[101];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,op,ed,F,M,ans = INF; cin >> N;
    for(int i=1;i<=N;++i) cin >> cost[i];

    cin >> op >> ed >> F >> M;

    for(int i=0;i<M;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }

    for(int i=1;i<=100;++i) for(int j=1;j<=100;++j) for(int k=0;k<2;++k) dis[i][j][k] = INF;
    priority_queue<ppp,vector<ppp>,greater<ppp> > pq; //
    pq.push({{0,0},{op,false}}); // sum:fuel :: city : card_used

    while(!pq.empty())
    {
        int sum = pq.top().f.f;
        int fuel = pq.top().f.s;
        int city = pq.top().s.f;
        bool used = pq.top().s.s;
        pq.pop();

        if(city == ed)
        {
            if(!used) ans = min(ans,sum);
            else ans = min(ans,sum+cost[ed]*(F-fuel)); // + fuel cost
        }

        if(vst[city][fuel][used]) continue;
        vst[city][fuel][used] = true;

        for(auto it : v[city])
        {
            if(!used)
            {
                if(sum < dis[it.s][F-it.f][true]) // if use card and still cost less
                {
                    dis[it.s][F-it.f][true] = sum; // change to cheaper cost
                    pq.push({{sum,F-it.f},{it.s,true}}); // we use card so the sum is still the same // we also got the full-tank fuel so only calculate (full_tank - cost)
                                         // go to it.s     // card is now change to used
                }
            }

            for(int j=0;j+fuel<=F;++j)
            {
                if(j+fuel < it.f) continue; // we can't use fuel less than travel cost  so ... continue
                if(sum + j*cost[city] < dis[it.s][j+fuel-it.f][used])
                        // litre * cost of the oil from this city
                        // less than cost of visiting target with the same fuel left
                {
                    dis[it.s][j+fuel-it.f][used] = sum + (j*cost[city]); // cheaper cost
                    pq.push({{sum+(j*cost[city]),j+fuel-it.f},{it.s,used}}); // new cost / fuel / target city / used
                }
            }
        }



    }

    cout << ans; //ยากชิบหายเลย


    // NOTE : ข้อนี้จะไม่มีการเดินกลับหลังไปติดล฿ป เพราะcostมันจะมากกว่าที่จดไว้
}
