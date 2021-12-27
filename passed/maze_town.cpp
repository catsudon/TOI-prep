#include<bits/stdc++.h>
using namespace std;
int n,m;
int sx,sy,ex,ey;
bool vst[155][155];
int board[155][155]; // 0 = bomb // 1=space // 2=bombed
int memo[155][155];
int mn = INT_MAX;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


int dfs(int x,int y,int cnt,bool used)
{
   // if(x>n or x<1 or y>m or y<1) return 0;
    if(vst[x][y]) return 0;
    if(used and board[x][y]==0) return 0;
    vst[x][y] = true;

    if(board[x][y] == 0)
    {
        used = true;
        memo[x][y] = -1;
    }

    if(x == ex and y == ey)
    {
        mn = min(mn,cnt);
        vst[x][y] = false;
        return 0;
    }
    cerr << x << " " << y << " " << cnt <<endl;
    for(int i=0;i<4;++i)
    {
        dfs(x+dx[i],y+dy[i],cnt+1,used);
    }



    vst[x][y] = false;

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> sx >> sy >> ex >> ey;

    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin >> board[i][j];

    int cnt2=0;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(memo[i][j]==-1) cnt2++;

    dfs(sx,sy,0,false);
    cout << cnt2 << endl << mn;




}
