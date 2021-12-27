#include<bits/stdc++.h>
using namespace std;

typedef struct data
{
  int x,y,cnt;
  bool j,b,p;
};

string board[505];
const int INF = 1e9;
int dp[505][505][2][2][2]; // x y j b p
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int opx,opy,edx,edy;
int main()
{
    int n,m; cin >> n >> m;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) for(int k=0;k<2;++k) for(int l=0;l<2;++l) for(int o=0;o<2;++o) dp[i][j][k][l][o] = INF;
    for(int i=0;i<n;++i) cin >> board[i];
    for(int i=0;i<n;++i) for(int j=0;j<m;++j)
    {
        if(board[i][j] == 'S') opx=i,opy=j;
        if(board[i][j] == 'E') edx=i,edy=j;
    }

    queue<data> q; q.push({opx,opy,0,0,0,0});
    while(q.size())
    {
        data tomo = q.front();
        int X = tomo.x;
        int Y = tomo.y;
        q.pop();
        if(board[X][Y] == 'j') tomo.j = true;
        if(board[X][Y] == 'b') tomo.b = true;
        if(board[X][Y] == 'p') tomo.p = true;
        if(board[X][Y] == '#') continue;
        if(board[X][Y] == 'J' and !tomo.j) continue;
        if(board[X][Y] == 'B' and !tomo.b) continue;
        if(board[X][Y] == 'P' and !tomo.p) continue;

        if(dp[X][Y][tomo.j][tomo.b][tomo.p] <= tomo.cnt) continue;
        dp[X][Y][tomo.j][tomo.b][tomo.p] = tomo.cnt;
       // cerr << X << " " << Y << " " << tomo.cnt << endl;
        for(int i=0;i<4;++i)
        {
            int ax = X+dx[i];
            int ay = Y+dy[i];
            if(ax < 0 or ay < 0 or ax >=n or ay >=m) continue;
            q.push({ax,ay,tomo.cnt+1,tomo.j,tomo.b,tomo.p});
        }
    }


    int mn = min(dp[edx][edy][0][0][0],dp[edx][edy][0][0][1]);
    mn = min(mn,dp[edx][edy][0][1][0]);
    mn = min(mn,dp[edx][edy][0][1][1]);
    mn = min(mn,dp[edx][edy][1][0][0]);
    mn = min(mn,dp[edx][edy][1][0][1]);
    mn = min(mn,dp[edx][edy][1][1][0]);
    mn = min(mn,dp[edx][edy][1][1][1]);

    if(mn == INF) cout << -1;
    else cout << mn;



}
