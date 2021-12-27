#include<bits/stdc++.h>
using namespace std;
int qs[2009][2009];
int mx = -40000000;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin >> qs[i][j];
            qs[i][j] += qs[i][j-1];
        }
    }

    for(int i=1;i<=n-k+1;++i)
    {
        for(int j=1;j<=m-k+1;++j)
        {
            int s=0;
            for(int r=0;r<k;++r)
            {
                s+= qs[i+r][j+r] - qs[i+r][j-1];
            }
            mx = max(mx,s);
        }
    }

    for(int i=1;i<=n-k+1;++i)
    {
        for(int j=m;j>=k;--j)
        {
            int s=0;
            for(int r=0;r<k;++r)
            {
                s+= qs[i+r][j] - qs[i+r][j-r-1];
            }
            mx = max(mx,s);
        }
    }


    cout << mx;
}
