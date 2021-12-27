#include<bits/stdc++.h>
using namespace std;
int board[2009][2009];
int qs[2009][2009]; /// vertical | | |

int qs2[2009][2009]; ///  diagonal  \ \ \

int qs3[2009][2009]; /// diagonal / / /
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin >> n >> m >> k;

    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
    {
        cin >> board[i][j];
    }

    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
    {
        qs[i][j] = qs[i-1][j] + board[i][j];
        qs2[i][j] = qs2[i-1][j-1] + board[i][j];
        qs3[i][j] = qs3[i-1][j+1] + board[i][j];
    }

    int mx = -INT_MAX;
    for(int i=k;i<=n;++i)
    {
        int bsum = 0;
        for(int l=0;l<k;++l) bsum+=qs[i][l+1]-qs[i-k+l][l+1]; //base triangle
        mx = max(mx,bsum);
        // cerr << mx << endl;
        for(int j=k+1;j<=m;++j)
        {
            bsum -= qs[i][j-k] - qs[i-k][j-k];// cerr << bsum << " ";
            bsum += qs2[i][j] - qs2[i-k][j-k];
            mx = max(mx,bsum);
            // cerr << bsum << endl;

        }
    }
    for(int i=k;i<=n;++i)
    {
        int bsum = 0;
        for(int l=0;l<k;++l) bsum+=qs[i][m-l]-qs[i-k+l][m-l]; //base triangle
        mx = max(mx,bsum);
         //cerr << mx << endl;
        for(int j=m-k;j>0;--j)
        {
            bsum -= qs[i][j+k] - qs[i-k][j+k]; //cerr << bsum << " ";
            bsum += qs3[i][j] - qs3[i-k][j+k];
            mx = max(mx,bsum);
             //cerr << bsum << endl;

        }
    }

    cout << mx;
}
