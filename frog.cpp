#include<bits/stdc++.h>
#define R first
#define D second
using namespace std;
using pii = pair<int,int>;
int dp[250][250];
pii board[250][250];
int n,m;

int solve(int x,int y,int c)
{
    if(x>n or y>m) return 0;
    if(dp[x][y] <= c) return 0;
    dp[x][y] = c;
  //  cerr << x << " " <<  y << endl;
    c++;
    for(int i=1;i<=board[x][y].R;++i) solve(x,y+i,c);
    for(int i=1;i<=board[x][y].D;++i) solve(x+i,y,c);

}


int main()
{
    for(int i=0;i<250;++i) for(int j=0;j<250;++j) dp[i][j] = 8922139;
    cin >> n >> m;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin >> board[i][j].R;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin >> board[i][j].D;
    n--;m--;
    solve(0,0,0);
    cout << dp[n][m];
}
