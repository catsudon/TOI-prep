#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,pair<int,int> >;

bitset<7009> pic[7009];
bitset<7009> vst[7009];
int dp[7009][7009];
int counter[7009];
queue<pii> q;
int dx[3] = {0,-1,-1};
int dy[3] = {-1,-1,0};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,m; cin >> n >> m;
    int sum = n*m;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
    {
        dp[i][j] = 37041;
        char a; cin >> a;
        pic[i][j] = a-'0';

        if(!pic[i][j])
        {
            dp[i][j] = 0;
            q.push({0,{i,j}});
        }
    }
    for(int i=1;i<=n;++i) q.push({0,{i,m+1}});
    for(int i=1;i<=m;++i) q.push({0,{n+1,i}});

    while(q.size())
    {
        int round = q.front().f;
        int x     = q.front().s.f;
        int y     = q.front().s.s;
        q.pop();

        for(int i=0;i<3;++i)
        {
            int ax = x+dx[i];
            int ay = y+dy[i];
            if(ax < 1 or ay < 1 or vst[ax][ay] or round+1 >= dp[ax][ay]) continue;
            dp[ax][ay] = round+1;
            vst[ax][ay] = 1;
            q.push({round+1,{ax,ay}});

        }
    }


    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(dp[i][j] == 37041) continue;
            counter[dp[i][j]] ++;
        }
    }

    int totalLoss = 0;
    for(int i=0;i<min(n,m);++i)
    {
        totalLoss += counter[i];
        cout << sum - totalLoss << endl;
    }



}
