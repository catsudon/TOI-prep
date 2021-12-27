#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 10001;
ll dp[1009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    dp[0]=1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=n;++i)
    {
        for(int j=1;j<i;++j)
        {
            dp[i] += (i-j) * dp[j];
            dp[i]%=mod;
        }
        dp[i]++; // only base

    cerr << dp[i] << endl;
    }


}
