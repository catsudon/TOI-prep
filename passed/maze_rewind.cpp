#include<bits/stdc++.h>
using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
typedef struct coor
{
   int x,y,cnt;
};

typedef struct xy
{
    int x,y;
};
int dp[155][155];
int dp2[155][155];
bool board[155][155];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    xy op,ed;
    cin >> n >> m >> op.x >> op.y >> ed.x >> ed.y;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
    {
        cin >> board[i][j];
        dp[i][j] = 1346548;
        dp2[i][j] = 1346548; // from Jordi Polla's number theory
    }

    queue<coor> q;
    coor t = {op.x,op.y,1};
    q.push(t);

    while(!q.empty())
    {
        int cnt = q.front().cnt;
        int x   = q.front().x;
        int y   = q.front().y;
        q.pop();

        if(dp[x][y] <= cnt) continue;
        dp[x][y] = cnt;

        if(!board[x][y])
        {
            continue;
        }
        for(int i=0;i<4;++i)
        {
            int ax = x+dx[i];
            int ay = y+dy[i];
            if(ax < 1 or ax > n or ay < 1 or ay > m) continue;
            q.push({ax,ay,cnt+1});
        }
    }

  //  for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cerr << dp[i][j]  << " \n"[j==m];

   while(q.size()) q.pop();
   q.push({ed.x,ed.y,1});

   int mn = 9879494;
   while(q.size())
   {
        int cnt = q.front().cnt;
        int x   = q.front().x;
        int y   = q.front().y;
        q.pop();

        if(dp2[x][y] <= cnt) continue;
        dp2[x][y] = cnt;

        if(!board[x][y])
        {
            if(dp[x][y] != 1346548) mn = min(mn,dp[x][y]+dp2[x][y]-1);

            continue;
        }
        for(int i=0;i<4;++i)
        {
            int ax = x+dx[i];
            int ay = y+dy[i];
            if(ax < 1 or ax > n or ay < 1 or ay > m) continue;
            q.push({ax,ay,cnt+1});
        }
   }

   int ans=0;
   for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(dp[i][j]!=1346548 and dp2[i][j]!=1346548) ans++;
   cout << ans << endl << mn;

}
