#include<bits/stdc++.h>
#define f first
#define s second
const int INF = 1e9;
using namespace std;
using pii = pair<int,int>;
pii dp[509][509]; /// L : R
int a[509];
int k,mx=0;
int solve()
{
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int o; cin >> o >> k;
    while(o--)
    {
        int n; cin >> n;
    for(int i=1;i<=n;++i) cin >> a[i];
    for(int i=1;i<=n;++i)
    {
        dp[i][i]  = {1,1};
    }
    for(int len = 1;len < n;++len)
    {
        for(int l=1,r=l+len;l<=n;++l,++r)
        {
            if(r > n) break;
            // worst case is to start with a new pan
            dp[l][r] = {dp[l+1][r].f+10 , 1 };
            for(int p=l+1;p<=r;++p) // try to merge the queue together
            {
                if(a[l]==a[p])
                {
                    int sum = dp[l][p-1].f + dp[p][r].f -1;
                    int mem = dp[l][p-1].s + dp[p][r].s;
                    if(mem >= k ) sum++ , mem = mem%k;
                    if(sum < dp[l][r].f) dp[l][r] = {sum,mem};
                    else if(sum == dp[l][r].f) dp[l][r].s = min(dp[l][r].s,mem);
                }
                else
                {
                    int sum = dp[l][p-1].f + dp[p][r].f;
                    int mem = min(dp[l][p-1].s , dp[p][r].s)+1;
                    if(mem >= k ) sum++ , mem = mem%k;
                    if(sum < dp[l][r].f) dp[l][r] = {sum,mem};
                    else if(sum == dp[l][r].f) dp[l][r].s = min(dp[l][r].s,mem);
                }
            }
        //    cerr << l << ' ' << r << ' ' << dp[l][r].f << ' ' << dp[l][r].s << endl;
        }
    }
    mx = max(dp[1][n].f,mx);
    }
    cout << mx;
}
