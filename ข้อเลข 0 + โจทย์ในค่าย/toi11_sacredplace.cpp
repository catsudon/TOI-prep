#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
vector<pii> v[200009];
bool vst[200009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,e;
    cin >> n >> e;
    for(int i=0;i<e;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    priority_queue<pii> pq;
    pq.push({1,1});
    long long sum=0;
    while(!pq.empty())
    {
        int F = pq.top().f;
        int S = pq.top().s;
        pq.pop();
        if(vst[S]) continue;
        vst[S]=true;
      //  cout << F << " " << S << "\n";
        for(auto it : v[S])
        {
            if(!vst[it.s]) pq.push(it);
        }
        sum+=F-1;
    }
    cout << sum;
}
