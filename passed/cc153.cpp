#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using pip = pair<pii,pii>;
using ppp = pair<pip,pii>;

char a[209][209];
bool vst[209][209][7][128]; // x y time bitset
int dx[5] = {0,0,0,1,-1};
int dy[5] = {0,1,-1,0,0};
int gemID[209][209];
queue<ppp> q;  // time : cnt :: x : y :: bitset

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,m; cin >> n >> m;
    int p =0;

    for(int i=1;i<=200;++i) for(int j=1;j<=200;++j) gemID[i][j] = -1;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
    {
        cin >> a[i][j];
        if(a[i][j] == 'G') gemID[i][j] = p++;
        if(a[i][j] == 'S')
        {
            a[i][j] = '.';
            q.push({{{1,0},{i,j}},{0,0}});
        }
    }

    while(q.size())
    {
        int time = q.front().f.f.f;
        int cnt  = q.front().f.f.s;
        int x    = q.front().f.s.f;
        int y    = q.front().f.s.s;
        int have = q.front().s.f;
        int nub  = q.front().s.s;
        q.pop();

        if(have == 127) {cout << nub; return 0;}

        for(int i=0;i<5;++i)
        {
            int xx = x+dx[i];
            int yy = y+dy[i];
            int ncnt = cnt;
            int nhave = have;
            if(xx < 1 or yy < 1 or xx > n or yy > m or a[xx][yy] == '#') continue;

            int toki = time+1; toki%=6; if(toki==0) toki=6;
            if(a[xx][yy] == 'G' )
            {
                int id = gemID[xx][yy];
                int cf = (1<<id);
                if(have != (have|cf) ) ncnt++,nhave = (have|cf);

            }
            if(a[xx][yy] == 'G' or a[xx][yy] == '.')
            {
                if(vst[xx][yy][toki][nhave]) continue;
                vst[xx][yy][toki][nhave] = 1;
                q.push({{{toki,ncnt},{xx,yy}},{nhave,nub+1}});
            }
            else
            {
                int base = a[xx][yy] - 48;
                if((base <= ncnt or base == toki) and !vst[xx][yy][toki][nhave])
                {
                    vst[xx][yy][toki][nhave]=1;
                    q.push({{{toki,ncnt},{xx,yy}},{nhave,nub+1}});
                }
            }

        }

    }

    cout << -1;


}
