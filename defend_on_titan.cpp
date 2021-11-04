#include<bits/stdc++.h>
using namespace std;
int a[1009][1009];
int bestcol[1009]; /// key = | val = - - - | -
                        ///  |
                        ///  |

int main()
{
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin >> a[i][j];
    long long sum=0;
    for(int i=1;i<=n;++i)
    {
        int mn = INT_MAX;
        int mem = 0;
        for(int j=1;j<=n;++j)
        {
            if(a[i][j] < mn) mn = a[i][j],mem=j;
            else if(a[i][j]==mn) cerr << "I got a problem now\n";
        }
        bestcol[i] = mem;
    }

}
