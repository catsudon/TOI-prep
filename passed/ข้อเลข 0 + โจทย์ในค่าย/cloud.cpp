#include<bits/stdc++.h>
using namespace std;
int m,n,t;
int cnt=0;
int mx=0;
char sky[109][109];

int start(int x,int y,int c)
{
    c++;
    sky[x][y]='#';
    if(c>=t) if(c>mx) mx=c;
    if(sky[x+1][y]=='.') c = start(x+1,y,c);
    if(sky[x-1][y]=='.') c = start(x-1,y,c);
    if(sky[x][y+1]=='.') c = start(x,y+1,c);
    if(sky[x][y-1]=='.') c = start(x,y-1,c);
    if(sky[x+1][y+1]=='.') c = start(x+1,y+1,c);
    if(sky[x+1][y-1]=='.') c = start(x+1,y-1,c);
    if(sky[x-1][y+1]=='.') c = start(x-1,y+1,c);
    if(sky[x-1][y-1]=='.') c = start(x-1,y-1,c);

    return c;

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin >> sky[i][j];
        }
    }
    cin >> t;
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(sky[i][j]=='.') {int a = start(i,j,0); if(a>=t)cnt++;if(a>mx)mx=a;}
        }
    }

    cout << cnt << " " << mx;
}
