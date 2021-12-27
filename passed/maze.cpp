#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n,m,opx,opy,edx,edy;
bool board[155][155];
int dp[155][155];
int dp2[155][155];

int main()
{
    cin >> n >> m >> opx >> opy >> edx >> edy;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin >> board[i][j];
    for(int i=0;i<155;++i) for(int j=0;j<155;++j)
    {
        dp[i][j] = 9999999;
        dp2[i][j] = 9999999;
    }

    queue<pair<int,pii > > q;
    q.push({1,{opx,opy}});
    while(q.size())
    {
        int x = q.front().s.f;
        int y = q.front().s.s;
        int cnt = q.front().f;
        q.pop();
        if(dp[x][y] <= cnt) continue;
        dp[x][y] = cnt;
        if(x == edx and y == edy) continue;
        cnt++;

        if(board[x][y]!=0)
        for(int i=0;i<4;++i)
        {
            int ax = x+dx[i];
            int ay = y+dy[i];
            if(ax > n or ay > m or ax < 1 or ay < 1) continue;
            q.push({cnt,{ax,ay}});
        }
    }
    queue<pair<pair<int,bool>,pii > > qq;
    qq.push({{0,false},{edx,edy}});
    while(qq.size())
    {
        int x = qq.front().s.f;
        int y = qq.front().s.s;
        int cnt = qq.front().f.f;
        bool used = qq.front().f.s;
        q.pop();
        if(dp2[x][y] <= cnt) continue;
        if(board[x][y]==0 and used) continue;
        if(board[x][y]==0 and !used) used = true;
        dp2[x][y] = cnt++;
        cerr << x << " " << y << " " << cnt << " " << used << endl;

        for(int i=0;i<4;++i)
        {
            int ax = x+dx[i];
            int ay = y+dy[i];
            if(ax > n or ay > m or ax < 1 or ay < 1) continue;
            qq.push({{cnt,used},{ax,ay}});
        }
    }

    int c=0;
    int mn = 46488974;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
    {
        if(dp[i][j] !=9999999 and dp2[i][j]!=9999999 and board[i][j]==0)
        {
            c++;
            mn = min(mn,dp[i][j]+dp2[i][j]);
        }
        else if(dp[i][j] !=9999999 and dp2[i][j]!=9999999) mn = min(mn,dp[i][j]+dp2[i][j]);
        dp[i][j] == 9999999 or dp2[i][j] == 9999999 ? cerr << -1 : cerr << dp[i][j]+dp2[i][j];
        cerr << " \n"[j==m];

    }
    if(mn==4648894) mn=0;
    cout << c << endl << mn ;

}
