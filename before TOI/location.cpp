#include<bits/stdc++.h>
using namespace std;

int qs[1009][1009];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,m,k; cin >> n >> m >> k;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
    {
        cin >> qs[i][j];
        qs[i][j] += qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
    }

    int mx=0;
    for(int i=k;i<=n;++i) for(int j=k;j<=m;++j)
    {
        int chg = qs[i][j] - qs[i][j-k] - qs[i-k][j] + qs[i-k][j-k];
   //     cerr << chg << endl;
        mx = max(mx,chg);
    }
    cout << mx;


}
