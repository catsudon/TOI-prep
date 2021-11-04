#include<bits/stdc++.h>
using namespace std;
int GO,CHG,CUT,n,m;
char board[109][109];
int dp[2][109][109];
// up = {-1,0}
// go = {0,1}
int mn = INT_MAX;
int sol(int x,int y,int sum,bool up) // 1 = up 0 = straight
{
    if(board[x][y]=='X') sum+= CUT;
    if(!(x==n and y==0) and dp[up][x][y] <= sum) return 0;
    if(x==1 and y==m)
    {
        mn = min(mn,sum);
        return 0;
    }
    dp[up][x][y] = sum;
    // up
    if(up) sol(x-1,y,sum+GO,1);
    else sol(x-1,y,sum+CHG,1);
    // right
    if(!up) sol(x,y+1,sum+GO,0);
    else sol(x,y+1,sum+CHG,0);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> GO >> CHG >> CUT >> m >> n;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin >> board[i][j];
   for(int k=0;k<2;++k) for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) dp[k][i][j] = INT_MAX;
    sol(n,1,0,0);
    sol(n,1,0,1);
    cout << mn+CHG;
 /*   cerr << endl << endl;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j) cerr << dp[i][j] << " ";
        cerr << endl;
    } */
}
