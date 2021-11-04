#include<bits/stdc++.h>
using namespace std;
int dp[1000009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    long long cnt = 0;
    for(int i=0;i<n;++i)
    {
        int a; cin >> a;
        cnt+=(long long)dp[max(0,m-a)];
        dp[a]++;
    }
    cout << cnt;
}
