#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ppp = pair<pii,int>;
const int N = 209;
vector<pii> v[209];
vector<int> shop;
int dp[N][N];
int deepee[N];
bool vst[N];
int mn;
int n,m,k;

int dfs(int pos,int cnt ,int sum)
{
    if(vst[pos] or sum >= mn) return 0;
    vst[pos]=1;
    if(cnt == k) mn = min(mn,sum+dp[pos][n]);
    else
    {
        for(auto it : shop)
        {
            if(vst[it]) continue;
            dfs(it,cnt+1,sum+dp[pos][it]);
        }
    }
    vst[pos]=0;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=k;++i)
    {
        int a; cin >> a;
        shop.emplace_back(a);
    }
    while(m--)
    {
        int a,b,c; cin >> a >> b >> c;
        v[a].emplace_back(c,b);
        v[b].emplace_back(c,a);
    }
    for(int i=0;i<=n+1;++i) for(int j=0;j<=n+1;++j) dp[i][j] = INT_MAX;


    for(int b=1;b<=n;++b)
    {
        priority_queue<pii,vector<pii>,greater<pii> > pq; // sum :: pos
        pq.push({0,b});
        dp[b][b] = 0;
        while(pq.size())
        {
            int sum = pq.top().f;
            int pos = pq.top().s;
            pq.pop();


            for(auto it : v[pos])
            {
                int cost = it.f;
                int next = it.s;
                if(dp[b][next] <= sum+cost) continue;
                dp[b][next] = sum+cost;
                pq.push({sum+cost,next});
            }
        }
    }

    int ans = INT_MAX;
    for(auto starter : shop)
    {
        int op = dp[1][starter];
        int deepee[209];
        for(int i=1;i<=200;++i) vst[i] = 0;
        mn = INT_MAX;
        dfs(starter,1,op);
        ans = min(mn,ans);
    }

    cout << ans;

}
