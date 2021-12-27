#include<bits/stdc++.h>
#pragma GCC optimization ("O3")
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ppp = pair<int,pii>;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k; cin >> k;
    while(k--)
    {     //100  100  1k  100
        int n,m,ghost,T,opx,opy; cin >> n >> m >> ghost >> T >> opx >> opy;
        ppp G[ghost+9]; string a[n+9];
        for(int i=1;i<=ghost;++i) cin >> G[i].f >> G[i].s.f >> G[i].s.s;
        for(int i=1;i<=n;++i) {cin >> a[i]; a[i] = " "+a[i];}

        int dp[ghost+2][n+9][m+9];
        int DP[n+9][m+9];
        for(int k=1;k<=ghost;++k) for(int i=0;i<=n+1;++i) for(int j=0;j<=m+1;++j) dp[k][i][j] = 5555;
        for(int i=0;i<=n+1;++i) for(int j=0;j<=m+1;++j) DP[i][j] = 5555;
        for(int i=1;i<=ghost;++i)
        {
            int xx = G[i].s.f+1;
            int yy = G[i].s.s+1;
            int op = G[i].f; // min(op + time , dp[x][y])
            queue<ppp> q; // time : x,y
            q.push({op,{xx,yy}});

            while(q.size())
            {
                int t = q.front().f;
                int x = q.front().s.f;
                int y = q.front().s.s;
                q.pop();
                if(dp[i][x][y] <= t) continue;
                if(t > T) continue;
       //         cerr << " ghost "  << i << " " << t << " " << x << " " << y << endl;
                dp[i][x][y] = t;
                DP[x][y] = min(DP[x][y],t);

                t++;
                for(int o=0;o<4;++o)
                {
                    int ax = x+dx[o];
                    int ay = y+dy[o];
                    if(ax > n or ax < 1 or ay > m or ay < 1) continue;
                    if(DP[ax][ay] <= t) continue;
                    if(a[ax][ay] == '#') continue;
                    q.push({t,{ax,ay}});
                }
            }
  //          for(int ii = 1 ; ii <= n ; ++ii)
    //        {
      //          for(int jj = 1 ; jj <= m ; ++jj ) if(dp[i][ii][jj]!=5555) cerr << dp[i][ii][jj] << " "; else cerr << "X ";
        //        cerr << endl;
          //  }cerr << endl;

        }

        // pacman
        int pacman[n+9][m+9];
        for(int i=0;i<=n+1;++i) for(int j=0;j<=m+1;++j) pacman[i][j] = 5555;
        int die = 1;
        queue<ppp> pm; // t : x,y
        pm.push({0,{opx+1,opy+1}});
        while(pm.size())
        {
            int t = pm.front().f;
            int x = pm.front().s.f;
            int y = pm.front().s.s;
            pm.pop();
            if(t == pacman[x][y]) continue;
            if(DP[x][y] <= t) continue;
            if(t==T) {die=0; break;}
            pacman[x][y] = t;
         //   cerr << "pacman " << t << " " << x << " " << y << endl;
            t++;
            for(int o=0;o<4;++o)
            {
                int ax = x+dx[o];
                int ay = y+dy[o];
                if(ax > n or ax < 1 or ay > m or ay < 1 or t>T) continue;
                if(DP[ax][ay] <= t) die=1;
                if(a[ax][ay] == '#') continue;
                pm.push({t,{ax,ay}});
            }
            pm.push({t,{x,y}});

        }
        if(die) cout << "NO\n";
        else cout << "YES\n";
    }
}
