#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
bool vst[2509];
vector<pii> v[2509];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=0;i<m;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        v[a].push_back({c-1,b});
        v[b].push_back({c-1,a});
    }
    int op,ed,tourist;
    cin >> op >> ed >> tourist;
    int least=INT_MAX;
    priority_queue<pii> pq;
    pq.push({INT_MAX,op});
    while(!pq.empty())
    {
        int mn  = pq.top().f;
        int pos = pq.top().s;
        pq.pop();
        if(vst[pos]) continue;
        vst[pos] = true;

        if(pos==ed)
        {
            least = mn;
            break;
        }
        for(auto it : v[pos])
            if(!vst[it.s])
            pq.push({min(mn,it.f) , it.s});
    }

    if(tourist%(least)==0) cout << tourist/(least);
    else cout << (tourist/(least))+1;
}
