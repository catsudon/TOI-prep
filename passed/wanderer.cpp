#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ppp = pair<pii,int>;
int dp[100009][11];
vector<pii> v[100009];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,e,q;
    scanf("%d%d%d",&n,&e,&q);
    while(e--)
    {
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }

    for(int i=1;i<=n;++i) for(int j=0;j<=q;++j) dp[i][j] = INT_MAX;

    priority_queue<ppp,vector<ppp>,greater<ppp> > pq; // sum : pos : cooldown
    pq.push({{0,1},0});

    while(pq.size())
    {
        int sum = pq.top().f.f;
        int pos = pq.top().f.s;
        int cooldown = pq.top().s;
        pq.pop();

        if(dp[pos][cooldown] <= sum ) continue;
        dp[pos][cooldown] = sum;

        if(pos == n)
        {
            printf("%d",sum); return 0;
        }

        for(auto it : v[pos])
        {
            if(cooldown == 0 )
            {
                pq.push({{sum,it.s},q-1});
            }
            pq.push({{sum+it.f,it.s},max(0,cooldown-1)});
        }

    }


}
