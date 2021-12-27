#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int t[n][n];
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) cin >> tile[i][j];

    int cnt=-1;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(tile[i][j] == tile[i][j+1] and tile[i+1][j] == tile[i][j] and tile[i][j]!=tile)
            {
                tile[i][j] = cnt;
                tile[i+1][j] = cnt;
                tile[i][j+1] = cnt;

                cnt--;
            }
        }
    }


}
