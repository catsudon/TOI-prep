#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
const int INF = 2e8;
int dp[1009][1009];
int shoujo[1009][1009];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main()
{
    int n; cin >> n;
    bool x=0;
    int ox,oy,ex,ey;
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
    {
        dp[i][j] = INF;
        cin >> shoujo[i][j];
        if(shoujo[i][j] == 0 and !x) ox=i,oy=j,x=true;
        else if(shoujo[i][j] == 0 and x) ex=i,ey=j;
    }
    priority_queue<pair<int,pii>,vector<pair<int,pii> >,greater<pair<int,pii> > > q; q.push({0,{ox,oy}});
    int mn = INF;

    while(!q.empty())
    {
        int x = q.top().s.f;
        int y = q.top().s.s;
        int mx = q.top().f;
        q.pop();
        if(mx >= dp[x][y]) continue;
        mx = max(mx,shoujo[x][y]);
        dp[x][y] = mx;
        if(x == ex and y == ey)
        {
            mn = min(mn,mx);
            break;
        }
        for(int i=0;i<4;++i)
        {
            int ax = x+dx[i];
            int ay = y+dy[i];
            if(ax > n or ay > n or ax < 1 or ay < 1) continue;
            q.push({mx,{ax,ay}});
        }
    }

    cout << mn;

}
