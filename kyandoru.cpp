#include<bits/stdc++.h>
using namespace std;
char candle[2009][2009];
bool vst[2009][2009];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
int main()
{
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin >> candle[i][j];
    int cnt=0; n++;m++;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
    {
        if(candle[i][j] == '1' and !vst[i][j]){
        queue<pii> q;
        q.push({i,j}); cnt++;
        while(q.size())
        {
            int x = q.front().f;
            int y = q.front().s;
            q.pop();
            if(vst[x][y] or candle[x][y]=='0') continue;
            vst[x][y] = true;
            //cerr << x << " " << y << " " << cnt << endl;
            for(int i=0;i<8;++i)
            {
                int ax = x+dx[i];
                int ay = y+dy[i];
                if(ax < 1 or ax > n or ay < 1 or ay > m ) continue;
                if(vst[ax][ay]) continue;
                if(candle[ax][ay] == '1') q.push({ax,ay});
            }
        }
        }
    }

    cout << cnt;

}
