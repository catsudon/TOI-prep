#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m; cin  >> n >> m;
    int riru[n][m];
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin >> riru[i][j];
    for(int i=0;i<n;++i) {for(int j=0;j<m;++j)
    {
        int a; cin >> a;
        cout << riru[i][j]+a << " ";
    }cout << endl;}
}
