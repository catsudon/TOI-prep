#include<bits/stdc++.h>
using namespace std;

int dp[50009];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,m; cin >> n >> m;
    dp[0]=1;
    while(n--)
    {
        int a; cin >> a;

        for(int mm = m ; mm >= a ; --mm)
        {
            dp[mm] += dp[mm-a];
            dp[mm] %= 1000007;
        }
    }

    cout << dp[m];
}
