#include<bits/stdc++.h>
using namespace std;
int n,m;
int riru[1009][1009];
bool vst[1009][1009];

int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;++i)
    {
        int a,b; cin >> a >> b;
        riru[a][b] = i;
    }
    while(m--)
    {
        int x,y,k,c=0; cin >> x >> y >> k;
        for(int i=max(0,x-k);i<=min(1000,x+k);++i)
        {
            for(int j=max(0,y-k);j<=min(1000,y+k);++j)
                if(riru[i][j] and !vst[i][j])
                {
                    c++; vst[i][j] = true;
                }

        }
        cout << c << endl;
    }
}
