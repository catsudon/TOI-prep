#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int a[1009];
int dp[1009][3009]; // kanojo : price
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
    }


    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=3000;++j)
        {
            dp[i][j] = max({dp[i][j-1],dp[i][j]});
            if(a[i] == j) dp[i][j]++;
        }
    }



    cout << n-dp[n][3000];

}
