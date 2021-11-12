#include<bits/stdc++.h>
using namespace std;

int qs1[2009][2009]; // | | |

int qs2[2009][2009]; // \ \ \

int qs3[2009][2009]; // / / /

int main()
{
    int n,m,k; cin >> n >> m >> k;

    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
    {
        int a;
        cin >> a;
        qs1[i][j] = qs1[i-1][j]+a;
        qs2[i][j] = qs2[i-1][j-1]+a;
        qs3[i][j] = qs3[i-1][j+1]+a;
    }


    int mx = INT_MIN;
    for(int i=k;i<=n;++i)
    {
        // init
        int sum = 0;
        int p=i-k;
        for(int j=1;j<=k;++j)
        {
            sum+=qs1[i][j] - qs1[p++][j];
        }
        mx = max(mx,sum);
        for(int j=k+1;j<=m;++j)
        {
            sum-=qs1[i][j-k] - qs1[i-k][j-k];
            sum+=qs2[i][j] - qs2[i-k][j-k];
            mx = max(mx,sum);
        }
    }

    for(int i=k;i<=n;++i)
    {
        // init
        int sum = 0;
        int p=i-k;
        for(int j=m;j>=m-k;--j) sum+=qs1[i][j] - qs1[p++][j];
        mx = max(mx,sum);

        for(int j=m-k;j>=1;--j)
        {
            sum -= qs1[i][j+k] - qs1[i-k][j+k];
            sum += qs3[i][j] - qs3[i-k][j+k];
            mx = max(mx,sum);
        }
    }


    cout << mx;



}
