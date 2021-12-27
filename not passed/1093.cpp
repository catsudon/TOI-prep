#include<bits/stdc++.h>
using namespace std;
int a[2009];
int dp[2009]; // max of (i)
int sum[2009];
int main()
{
    int n; cin >> n;
    for(int i=1;i<=n;++i) cin >> a[i];
    for(int i=3;i<=n;++i) sum[i] = a[i-2]+a[i-1]-a[i];
    for(int i=1;i<=n;++i) cerr << sum[i] << "   ";
    for(int i=3;i<=n;++i)
    {
        dp[i] = max(dp[i-1] , sum[i]+dp[i-3]);
        cerr << i << ' ' << dp[i] << "       " << a[i-2]+a[i-1]-a[i] << " + " << dp[i-3] ;
        cerr << endl;
    }

    cout << dp[n];
}

