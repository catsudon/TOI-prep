#include<bits/stdc++.h>
using namespace std;
int dp[1000001];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    for(int i=0;i<n;++i)
    {
        int a,b;
        cin >> a >> b;
        dp[a]++;
        dp[b]--;
    }
    int mx=0;
    for(int i=1;i<=1000000;++i) dp[i]+=dp[i-1],mx=max(mx,dp[i]);

    cout << mx;


}
