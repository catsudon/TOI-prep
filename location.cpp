/*
TASK: location.cpp
LANG: C++
COMPILER: WCB
AUTHOR: Sathana Laolugsanalerd
CENTER: SSWIT
*/
#include<bits/stdc++.h>
using namespace std;
int table[1005][1005];
int main()
{
    int n,m,k; cin >> n >> m >> k;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            cin >> table[i][j];
            table[i][j]+=table[i][j-1]+table[i-1][j]-table[i-1][j-1];
        }
    int mx=0;
    int ans;
    for(int i=k;i<=n;++i)
    {
        for(int j=k;j<=m;++j)
        {
            ans = table[i][j] - table[i-k][j] - table[i][j-k] + table[i-k][j-k];
            mx = max(mx,ans);
        }
    }
    cout << mx;
}
