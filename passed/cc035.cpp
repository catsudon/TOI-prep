#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
pll a[100009]; // val : time
vector<int> adj[100009];
bool vst[100009];

int main()
{
    int n,e,op;
    cin >> n >> e >> op;
    for(int i=1;i<=n;++i){cin >> a[i].f; a[i].s = -1;}
    while(e--)
    {
        int chob , wow;
        cin >> chob >> wow;
        adj[chob].push_back(wow);
        adj[wow].push_back(chob);
    }

    queue<pll> q;
    q.push({op,0});
    while(q.size())
    {
        ll idx = q.front().f;
        ll time = q.front().s;
        q.pop();
        if(vst[idx]) continue;
        vst[idx]=1;
        a[idx].s = time;

        for(auto it : adj[idx])
        {
            if(vst[it]) continue;
            q.push({it,time+1});
        }
    }

    ll sum = 0; vector<pll> v;
    for(int i=1;i<=n;++i)
    {
        if(a[i].f <= 0 ) continue;
        if(a[i].s == -1) sum+=a[i].f;
        if(a[i].f > 0 and a[i].s != -1) v.push_back({-a[i].f,a[i].s});
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;++i) vst[i]=0;
    priority_queue<pll> pq;
    for(auto it : v)
    {
        int getto = -it.f;
        int time  = it.s;

        while(time--)
        {
            if(vst[time]) continue;
            sum+=getto; vst[time]=1;// cout << getto << ' ' << time << endl;
            break;
        }
    }
    cout << sum;

}
