#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int n,m;
int a[1010][1010];
int xx=0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<pair<int,int> > v;
bool vst[1010][1010];

int dfs(int x,int y)
{
    if(x<1 or y<1 or vst[x][y] or x>n or y>m or xx) return 0;
  //  cerr << x << " " << y << endl;
    v.push_back({x,y});
    vst[x][y] = true;
    if(x==n and y==m)
    {
        cout << 1 << endl;
        for(auto it : v) cout << it.f << " " << it.s << endl;
        xx=1;
    }

    for(int i=0;i<4;++i)
    {
        int ax = x+dx[i];
        int ay = y+dy[i];
      //  cerr << ax << " " << ay << endl;
        if(a[ax][ay] - a[x][y] > 1 or a[ax][ay] - a[x][y] < -1) continue;
       // cerr << ax << " " << ay << endl;
        dfs(ax,ay);
    }

    v.pop_back();
    vst[x][y] = false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin >> a[i][j];
    dfs(1,1);
    if(xx==0)
    cout << xx;
}
