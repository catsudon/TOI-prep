#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
for(int oo=0;oo<2;++oo)
{
    int n,m,r,c,t; cin >> n >> m;
    int table[n+1][m+1];
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=m;++j) table[i][j] = 0;
    }
    cin >> t;
    for(int i=0;i<t;++i)
    {
        cin >> r >> c;
        table[r+1][c+1] = 1;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            table[i][j] += table[i-1][j] + table[i][j-1] - table[i-1][j-1];
        }
    }
 /*   for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    } */
    for(int k=min(n,m);k>0;--k)
    {
        for(int i=k;i<=n;++i)
        {
            for(int j=k;j<=m;++j)
            {
                int big = table[i][j] - table[i-k][j] - table[i][j-k] + table[i-k][j-k];
                int small = table[i-1][j-1] - table[i-k+1][j-1] - table[i-1][j-k+1] + table[i-k+1][j-k+1];
                if(big-small == 0 )
                {
                    cout << k << "\n";
                    k=-1;
                    i=n+99;
                    j=m+99;
                    break;
                }
            }
        }
    }
   // for(int i=0;i<=m;++i) for(int j=0;j<=n;++j) table[i][j] = 0;
}
}
