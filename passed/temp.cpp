#include<bits/stdc++.h>
using namespace std;
int m,s,t;
int mountain[30][30];
int mx=-5;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int dfs(int x,int y)
{
    mx = max(mx,mountain[x][y]);

    for(int i=0;i<4;++i)
    {
        if(mountain[x+dx[i]][y+dy[i]] > mountain[x][y]) dfs(x+dx[i],y+dy[i]);
    }
}


int main()
{
    cin >> m >> s >> t;
    for(int i=1;i<=m;++i) for(int j=1;j<=m;++j) {cin >> mountain[i][j]; if(mountain[i][j]==100) mountain[i][j]=-98;}
    for(int i=0;i<25;++i) mountain[0][i] = -99,mountain[i][0] = -99,mountain[m+1][i] = -99,mountain[i][m+1] = -99;

    dfs(t,s);

    cout << mx;
}
