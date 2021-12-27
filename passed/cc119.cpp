#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int a[109][10009];
int dp[10009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,m,k; cin >> n >> m >> k;

    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin >> a[i][j];

    for(int i=1;i<=m;++i) dp[i] = a[n][i];
    for(int i=n-1;i>=1;--i)
    {
        priority_queue<pair<int,int> > pq;
        for(int j=1;j<=1+k;++j) pq.push({dp[j],j});
        for(int j=1;j<=m;++j)
        {
            while(pq.size() and pq.top().s < j-k) pq.pop();

            dp[j] = pq.top().f + a[i][j];
            if(j+1+k <= m ) pq.push({dp[j+1+k],j+1+k});
        }
    }

    int mx = 0;
    for(int i=1;i<=m;++i) mx = max(mx,dp[i]);
    cout << mx;
}

