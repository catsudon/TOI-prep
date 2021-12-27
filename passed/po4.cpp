#include<bits/stdc++.h>
using namespace std;
char a[1009];
int dp[1009][1009];

int solve(int l, int r)
{
    if(l>=r) return 0;
    if(dp[l][r] > 0) return dp[l][r];
    if(a[l]==a[r]) dp[l][r] = 1+solve(l+1,r-1);
    else
    for(int i=l;i<r;++i)
    {
        dp[l][r] = max(solve(l,i)+solve(i+1,r),dp[l][r]);
    }


    return dp[l][r];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
    }
    cout << solve(0,n-1);
}
