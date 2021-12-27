#include<bits/stdc++.h>
#define f first
#define s second
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ppp = pair<pii,pib>;
const int MXN = 155;
bool board[MXN][MXN];
int dp[MXN][MXN][2];
bool b[MXN][MXN];
set<pii> dp2[MXN][MXN];
int n,m,ox,oy,ex,ey,fin=0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> ox >> oy >> ex >> ey;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
    {
        cin >> board[i][j];
        dp[i][j][0] = 100009;
        dp[i][j][1] = 100009;
        b[i][j] = false;
    }
    queue<ppp> q;
    queue<pii> coor;
    q.push({{ox,oy},{1,false}});
    coor.push({-1,-1});

    while(q.size())
    {
        int x = q.front().f.f;
        int y = q.front().f.s;
        int lv = q.front().s.f;
        bool used = q.front().s.s;
        int cox = coor.front().f;
        int coy = coor.front().s;
        q.pop();
        coor.pop();

         //cerr << endl;
        //cerr << x << " " << y << " " << lv << " " << used << " " << cox << " " << coy;
        if(dp[x][y][used] <= lv and dp2[x][y].find({cox,coy}) != dp2[x][y].end()) continue;
        if(board[x][y] == 0)
        {
            if(used) continue;
            else
            {
                used = true;
                cox = x,coy = y;
            }
        }
        dp[x][y][used] = min(dp[x][y][used],lv);
        dp2[x][y].insert({cox,coy});
       //  //cerr << " passed";
        if(x==ex and y==ey)
        {
            b[cox][coy] = 1;
          //  cout << cox << " " << coy << endl;
            continue;
        }

        for(int i=0;i<4;++i)
        {
            int ax = x+dx[i];
            int ay = y+dy[i];
            if(ax < 1 or ax > n or ay < 1 or ay > m) continue;
            if(board[ax][ay] == 0 and used) continue;
            q.push({{ax,ay},{lv+1,used}});
            coor.push({cox,coy});
        }
    }

    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(b[i][j] == 1) fin++;
    cout << fin << endl << dp[ex][ey][1];
}
