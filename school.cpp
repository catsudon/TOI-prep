#include<bits/stdc++.h>
using namespace std;
int qs[80][80];
char a[80][80];
bool vst[80][80];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};
int mx=0,memo=0;

int dfs(int x,int y)
{
    if(vst[x][y]) return 0;
    vst[x][y] = true;
   // cerr << x << " " << y << endl;
    for(int i=0;i<4;++i)
    {
        int ax = x + dx[i];
        int ay = y + dy[i];
        if(!vst[ax][ay] and a[ax][ay]=='P')dfs(ax,ay);
    }
}

int main()
{
    memset(a,'X',sizeof a);
    int n,m; cin >> m >> n;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
    {
        cin >> a[i][j];
        if(a[i][j] == 'T') qs[i][j]++;
        qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
    }

    swap(m,n);
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            for(int co=1;co<=min(n,m);++co)
                {
                    int k = i+co;
                    int l = j+co;
                    if(k>m or l>n) continue;
                    int tree = qs[k][l] + qs[i-1][j-1] -qs[k][j-1] -qs[i-1][l];

                    if(tree >=1) continue;
                    int area = (1+k-i) * (1+l-j);
                    if(area >= mx)
                    {
                        int p = 0;
                        memset(vst,false,sizeof vst);
                        for(int d=i;d<=k;++d) for(int b=j;b<=l;++b) if(!vst[d][b] and a[d][b]=='P')
                        {
                            dfs(d,b); p++;
                        }
                        if(area==mx and p<memo) memo = p;
                        if(area > mx) mx = area,memo=p;

                    }
                }
        }
    }

    cout << mx << " " << memo;



}

