#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
vector<pii> v[3009];
bool vst[3009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,e; cin >> n >> e;
    while(e--)
    {
        int a,b,c,d; cin >> a >> b >> c >> d;
        if(d==1) c=0;
        v[a].push_back({c,b}); // dis : pos
        v[b].push_back({c,a}); // dis : pos
    }

    int p; cin >> p; vector<pii> promotion;
    while(p--)
    {
        int a,b; cin >> a >> b;
        promotion.push_back({a,b});
    }
    sort(promotion.begin(),promotion.end());
    for(int i=promotion.size()-2;i>=0;--i)
    {
        promotion[i].s = min(promotion[i+1].s,promotion[i].s);
    }

    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,1});
    int sum=0;
    while(pq.size())
    {
        int dis = pq.top().f; // distance
        int pos = pq.top().s;
        pq.pop();
        if(vst[pos]) continue;
        vst[pos] = true;
   //     if(pos==0) cerr << "found 0 " << dis << endl;

        if(dis!=0)
        {
            auto t = lower_bound(promotion.begin(),promotion.end(),make_pair(dis,0));
            sum+=t->s;
        }
        for(auto it : v[pos])
        {
            if(!vst[it.s]) pq.push({it.f,it.s});
        }
    }

    cout << sum;

}
