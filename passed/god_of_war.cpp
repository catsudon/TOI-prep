#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
const int N = 100009;
vector<pii> v[N];
bool vst[N];
int dp[N];
int mn_path = INT_MAX;
int n,e,op,ed;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> n >> e >> op >> ed;
    int ALL = 0;
    for(int i=1;i<=e;++i)
    {
        int a,b,c; cin >> a >> b >> c; ALL+=c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    for(int i=0;i<n;++i) dp[i] = INT_MAX;
    priority_queue<pair<int,pii>,vector<pair<int,pii> > , greater<pair<int,pii> > > pq; // sum :: pos : mx
    pq.push({0,{op,0}});
    int MNP=INT_MAX;
    while(pq.size())
    {
        int sum = pq.top().f;
        int pos = pq.top().s.f;
        int mx  = pq.top().s.s;
        pq.pop();
        if(dp[pos] <= sum - mx ) continue;
        dp[pos] = sum - mx;

        if(pos == ed )
        {
            MNP = min(MNP,sum-mx);
            continue;
        }

        for(auto it : v[pos])
        {
            int next = it.s;
            int that_will_cost = it.f;
            int newmx = max(mx,that_will_cost);
            if(dp[next] <= sum+that_will_cost - newmx) continue;
            pq.push({sum+that_will_cost,{next,newmx}});
        }
    }

    cout << ALL-MNP;

}
