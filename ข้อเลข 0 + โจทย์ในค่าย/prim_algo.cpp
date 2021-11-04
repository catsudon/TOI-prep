#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
vector<pair<int,int> > v[1009];
bool vst[1009];
int main()
{
    int n,e;
    cin >> n >> e;
    for(int i=0;i<e;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({-c,b});
        v[b].push_back({-c,a});
    }
    cout << "start from : ";int st; cin >> st;
    cout << "end at : ";int ed; cin >> ed;
    priority_queue<pair<int,int> > pq;
    pq.push({0,st});
    while(!pq.empty())
    {
        int F = pq.top().f;
        int S = pq.top().s;
        pq.pop();
        if(vst[S]) continue;
        vst[S] = true;
        if(ed==S)
        {
            cout << -F;
            return 0;
        }
        for(auto it : v[S])
        {
            if(!vst[it.s]) pq.push({it.f+F,it.s});
        }
    }
}
