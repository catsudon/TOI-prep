#include<bits/stdc++.h>
#define f first
#define s second
#define INF 1e9
using namespace std;
using pii = pair<int,int>;
using pib = pair<pii,bool>;


int dp[2001][2001][2];
bool rock[2001][2001];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp,9090909,sizeof dp);
    int n,m,k,op; cin >> n >> m >> k;
    for(int i=0;i<k;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        for(int j=b;j<=c;++j) rock[j][a] = true;
    }

    cin >> op;
    queue<pair<pib,int> > q;
    q.push({{{op,1},false},0});

    while(q.size())
    {
        int x = q.front().f.f.f;
        int y = q.front().f.f.s;
        bool used = q.front().f.s;
        int cnt = q.front().s;
        q.pop();

        if(dp[x][y][used] <= cnt or dp[x][y][false] <= cnt) continue;
        dp[x][y][used] = cnt++;

        for(int i=0;i<4;++i)
        {
            int ax = dx[i]+x;
            int ay = dy[i]+y;
            if(ax > n or ay > m or ax < 1 or ay < 1) continue;
            if(rock[ax][ay] and used) continue;
            if(rock[ax][ay]) q.push({{{ax,ay},true},cnt});
            else q.push({{{ax,ay},used},cnt});
        }
    }
    cout << min(dp[n][m][0],dp[n][m][1]);
}
