#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
pair<int,int> v[259][259];
int n,m;
int mn=INT_MAX;
int start(int x,int y,int step)
{
    if(x==n && y==m)
    {
        if(step<mn) mn = step;
        return 0;
    }
    step++;
    int F = v[x][y].first;
    int S = v[x][y].second;
    for(int i=1;i<=F;++i) start(x+i,y,step);
    for(int i=1;i<=S;++i) start(x,y+i,step);

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin >> v[i][j].f;
        }
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin >> v[i][j].s;
        }
    }

    start(1,1,0);
    cout << mn;

}
