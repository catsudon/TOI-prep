/*
TASK: shortkey.cpp
LANG: C++
COMPILER: LINUX
AUTHOR: Sathana Laolugsanalerd
ID: SSWIT
*/
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int INF = 1e7;
pii key[501];
int dp[200001][501];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,t; cin >> n >> k >> t;
    for(int i=1;i<=k;++i)
    {
        int s,e; cin >> s >> e;
        key[i] = {s,e};
    }
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=k;++j)
        {
            if(i==0 or j==0) continue;
            else if()
        }
    }

}
