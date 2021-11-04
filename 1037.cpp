#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
int n,m;
char board[60][60];
int flow[60][60];
int dp[60][60];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int main()
{
    cin >> n >> m;
    for(int i=0;i<60;++i) for(int j=0;j<60;++j) flow[i][j] = 6969969,dp[i][j]=6969969;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin >> board[i][j];
    int ex,ey,ox,oy;
    queue<pair<pii,int> > q;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
    {
        if(board[i][j] == '*') q.push({{i,j},0});
        if(board[i][j] == 'D') ex=i,ey=j;
        if(board[i][j] == 'S') ox=i,oy=j;
        if(board[i][j] == 'X') flow[i][j] = -1;
    }
    while(!q.empty())
    {
        int x = q.front().f.f;
        int y = q.front().f.s;
        int time = q.front().s;
        q.pop();
        if(flow[x][y] <= time or board[x][y]=='D') continue;
        flow[x][y] = time;
        time++;
        for(int i=0;i<4;++i)
        {
            int ax = dx[i]+x;
            int ay = dy[i]+y;
            if(ax > n or ay > m or ax < 1 or ay < 1) continue;
            q.push({{ax,ay},time});
        }
    }
    q.push({{ox,oy},0});
    while(q.size())
    {
        int x = q.front().f.f;
        int y = q.front().f.s;
        int time = q.front().s;
        q.pop();
        if(time >= dp[x][y] or flow[x][y] <= time) continue;
        cerr << x << " " << y << " " << time << endl;
        dp[x][y] = time;
        time++;
        for(int i=0;i<4;++i)
        {
            int ax = dx[i]+x;
            int ay = dy[i]+y;
            if(ax > n or ay > m or ax < 1 or ay < 1) continue;
            q.push({{ax,ay},time});
        }
    }
    if(dp[ex][ey] == 6969969) cout << "KAKTUS";
    else cout << dp[ex][ey];
}
