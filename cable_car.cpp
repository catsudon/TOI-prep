#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
vector<pii> v[2510];
bool vst[2510];

int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a,b,c; cin >> a >> b >> c;
        c--;
        v[a].emplace_back(c,b);
        v[b].emplace_back(c,a);
    }

    int op,ed,traveler;
    cin >> op >> ed >> traveler;
    priority_queue<pair<pii,int> > pq; // cost : destination :: min
    pq.push({{9999999,op},9999999});

    int mminn;
    while(!pq.empty())
    {
        int F = pq.top().f.f;
        int S = pq.top().f.s;
        int mn  = min(pq.top().s,F);
      //  cout << mn << " " << S << endl;
        pq.pop();
        if(vst[S]) continue;
        vst[S] = true;
        if(S==ed)
        {
            if(traveler%mn==0) cout << traveler/mn;
            else cout << traveler/mn + 1;

            return 0;
        }
        for(auto it : v[S]) if(!vst[it.s]) pq.push({it,mn});

    }
}
