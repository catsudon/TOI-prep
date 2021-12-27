/*
TASK: beehive.cpp
LANG: C++
COMPILER: WCB
AUTHOR: Sathana Laolugsanalerd
ID: SSWIT
*/
#include<bits/stdc++.h>
using namespace std;
int hive[1000][1000];
int dp[1000][1000];
pair<int,int> ans = {0,0}; // val/count
int n,m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) {cin >> hive[i][j];dp[i][[j]=}

    for(int i=0;i<m;++i)
        start(0,i,0);

    cout << ans.f << " " << (ans.s+2)/4;

}
