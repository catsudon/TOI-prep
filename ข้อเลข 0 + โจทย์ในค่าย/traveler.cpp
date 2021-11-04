#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
int n,m,st,ed,limit;
vector<pii> v[100009];
int dis[100009];
vector<bool> vst(100009,false);
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> st >> ed >> limit;
    for(int i=0;i<m;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    priority_queue<pii> pq;
    pq.push({0,st});
    while(!pq.empty())
    {
        int F = -pq.top().f; //cost
        int S = pq.top().s; //node
        pq.pop();
        if(vst[S]) continue;
     //   cout << F << " " << S << endl;
        vst[S]=true;
        dis[S]=F;
        for(auto it : v[S]) if(!vst[it.s]) pq.push({-(it.f+F),it.s});
    }
    if(dis[ed]<=limit) cout << ed << " " << dis[ed] << " " << 0;
    else
    {
        int over = dis[ed]-limit;
        int q=100009,e=INT_MAX;
     //   cout << "overflow = " << over << endl;
        pq.push({0,ed});
        vector<bool> vst(100009,false);
        while(!pq.empty())
        {
            int F = -pq.top().f;
            int S = pq.top().s;
            pq.pop();
            if(vst[S]) continue;
            vst[S]=true;
            if(F>=over && dis[S]<=limit)
            {
                if(F<e)
                {
                    e=F;
                    q=S;
                }
                else if(F==e) if(S<q) q=S;
            }
            for(auto it : v[S]) if(!vst[it.s]) pq.push({-(it.f+F),it.s});

        }
        cout << q << " " << dis[q] << " " << e;
    }

}
