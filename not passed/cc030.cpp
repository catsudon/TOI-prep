#include<bits/stdc++.h>
using namespace std;
int n,k;
int mx = 0;
int dp[509][509][50];
int a[509][509];
int dx[2] = {0,1};
int dy[2] = {1,0};

int sol(int x,int y,int mine,int sum)
{
    if(mine==k or x>n or y>n) return 0;
    for(int i=mine;i>=0;--i) if(dp[x][y][mine] >= sum) return 0;
    dp[x][y][mine] = sum;
    cerr << x << " " << y << " " << mine<< " " << sum << endl;

    /// decided to mine
    mine++;
    sum+=a[x][y];
    for(int i=0;i<2;++i)
    {
        int ax = x+dx[i];
        int ay = y+dy[i];cerr << " called for sol " << ax << " " << ay << " " << mine << " " << sum << endl;
        sol(ax,ay,mine,sum);
    }
    /// decided not to mine
    mine=0;
    sum-=a[x][y];
    for(int i=0;i<2;++i)
    {
        int ax = x+dx[i];
        int ay = y+dy[i];
        sol(ax,ay,mine,sum);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
    {cin >> a[i][j]; for(int o=0;o<=50;++o) dp[i][j][o] = -1;}
    sol(1,1,0,0);
    cout << mx;
}
