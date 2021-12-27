#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool fine[200][200],vst[200][200];
int dp1[200][200];
int dp2[200][200];
int cnt=0,mn = INT_MAX;

int main()
{
    int n,m,opx,opy,edx,edy;
    cin >> n >> m >> opx >> opy >> edx >> edy;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin >> fine[i][j];
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) dp1[i][j]=6969696,dp2[i][j]=6969696;

    queue<pair<int,pair<int,int> > > q; /// time :: x : y
    q.push({1,{opx,opy}});

    while(q.size())
    {
        int x = q.front().s.f;
        int y = q.front().s.s;
        int time = q.front().f;
        q.pop();
        if(dp1[x][y] <= time) continue;
        dp1[x][y] = time;

        if(!fine[x][y]) continue;// found bomb
        for(int i=0;i<4;++i)
        {
            int ax = x+dx[i];
            int ay = y+dy[i];
            if(ax > n or ay > m or ax < 1 or ay < 1) continue;
            q.push({time+1,{ax,ay}});
        }
    }


    q.push({1,{edx,edy}});
    while(q.size())
    {
        int x = q.front().s.f;
        int y = q.front().s.s;
        int time = q.front().f;
        q.pop();
        if(dp2[x][y] <= time) continue;
        dp2[x][y] = time;

        if(!fine[x][y])
        {
   //         if(dp1[x][y]==6969696) continue;
     //       if(!vst[x][y])cnt++;
       //     vst[x][y] = 1;
         //   mn = min(mn,dp2[x][y]+dp1[x][y]-1);
            continue;// found bomb
        }
        for(int i=0;i<4;++i)
        {
            int ax = x+dx[i];
            int ay = y+dy[i];
            if(ax > n or ay > m or ax < 1 or ay < 1) continue;
            q.push({time+1,{ax,ay}});
        }
    }

    cerr << endl << endl;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j) if(dp1[i][j]!=6969696) cerr << dp1[i][j] << " "; else cerr << "X ";
        cerr << endl;
    }
    cerr << endl << endl;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j) if(dp2[i][j]!=6969696) cerr << dp2[i][j] << " "; else cerr << "X ";
        cerr << endl;
    }


    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
    {
        if(dp1[i][j]== 6969696 or dp2[i][j] == 6969696 or fine[i][j]) continue;
        cnt++;
        cerr << i << " " << j << endl;
    }
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) mn = min(mn,dp1[i][j]-1+dp2[i][j]);




    cout << cnt << endl << mn;
}
