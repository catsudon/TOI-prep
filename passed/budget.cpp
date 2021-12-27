#include<bits/stdc++.h>
#define s second
#define f first
using namespace std;
using pii = pair<int,int>;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,e;
    cin >> n >> e;
    vector<pii> v[n+1];
    vector<bool> vst(n+1,false);
    for(int i=0;i<e;++i)
    {
        int s,t,d,r;
        cin >> s >> t >> d >> r;
        if(r==1)
        {
            v[s].push_back({0,t});
            v[t].push_back({0,s});
        }
        else
        {
            v[s].push_back({d,t});
            v[t].push_back({d,s});
        }
    }
    int p; cin >> p;
    vector<pii> promotion(p); // range and price;
    for(int i=0;i<p;++i)
    {
        int a,b;
        cin >> a >> b;
        promotion[i]={a,b};
    }
    sort(promotion.begin(),promotion.end());
   // for(auto it : promotion) cout << it.f << ":" << it.s << " " ;
    //cout << endl;
    for(int i=p-2;i>=0;--i)
    {
        promotion[i].s = min(promotion[i].s,promotion[i+1].s);
    }
    priority_queue<pii> pq; // distance and destination
    pq.push({0,1});
    int sum=0;
    while(!pq.empty())
    {
        int F = -pq.top().f; // distance
        int S = pq.top().s; // destination
        pq.pop();
        if(vst[S]) continue;
        vst[S] = true;
        if(F!=0)
        {
            auto temp = lower_bound(promotion.begin(),promotion.end(),make_pair(F,0));
            sum+=temp->s;
        }
     //   cout << F << " " << S << " " << "sum = " << sum << endl;
        for(auto it : v[S]) if(!vst[it.s]) pq.push({-(it.f),it.s});
    }
    cout << sum;
}

