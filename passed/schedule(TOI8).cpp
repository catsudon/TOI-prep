#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
pii dp[1001][1001];
int sum,xx,yy;
int fin = 9023;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp,50000,sizeof(dp));
    int n,t; cin >> t >> n;
    vector<int> a(n+1,0),b(n+1,0);

    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
        a[i] += a[i-1];
    }
    for(int i=1;i<=n;++i)
    {
        cin >> b[i];
        b[i] += b[i-1];
    }

    queue<pair<pii,pii> > q; // day :: a:b
    q.push({{0,0},{0,0}});

    while(!q.empty())
    {
        int x = q.front().s.f;
        int y = q.front().s.s;
        int day = q.front().f.f;
        int use = q.front().f.s;
        q.pop();
        if(dp[x][y].f < day) continue;
        if(dp[x][y].f == day and dp[x][y].s <= use) continue;
        dp[x][y].f = day;
        dp[x][y].s = use;

        /// ALL POSSIBLE
        if(x==n and y==n) continue;
        day++;
        for(int i=x;i<=n;++i)
        {
            int mxy=y;
            for(int j=y;j<=n;++j)
            {
                if(a[i]-a[x] + b[j]-b[y] <=t) mxy = j;
                else break;
            }
            if(a[i]-a[x] > t ) break;
     //       cout << "from x = " << x << " to " << i << "  : from y = " << y << " to " << mxy << " on day " << day << " total consume = " << a[i]+b[mxy]-a[x]-b[y] << endl;
            q.push({{day,a[i]-a[x] + b[mxy]-b[y]},{i,mxy}});

        }
    }

    cout << dp[n][n].f << endl << dp[n][n].s;


}
