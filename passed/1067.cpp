#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
int dx[5] = {0,-1,0,1,0};
int dy[5] = {0,0,1,0,-1};
char bruh[5] = {'X','N','E','S','W'};
int b[120][120];
bool vst[120][120];

int main()
{
    int n,m,q; cin >> m >> n >> q;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin >> b[i][j];

    while(q--)
    {
        int o,p; cin >> o >> p;
        for(int i=0;i<=101;++i)
            for(int j=0;j<=101;++j) vst[i][j] = 0;
        queue<pii> q; bool cyc = 0;
        q.push({p,o});
        while(q.size())
        {
            int x = q.front().f;
            int y = q.front().s;
            q.pop();
            if(vst[x][y]) { cout << "NO\n"; break; }
            vst[x][y] = true;
          //  cerr << x << " " << y;

            int ax = x+dx[b[x][y]];
            int ay = y+dy[b[x][y]];
            if(ax > n or ay > m or ax < 1 or ay < 1)
            {
                cout << bruh[b[x][y]] << endl; break;
            }
            else q.push({ax,ay});
        }
    }

}
