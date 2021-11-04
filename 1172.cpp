#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[1009];

ll sol(int lv)
{
    if(lv <=1) return 1;
    if(dp[lv] == 0) return dp[lv] = sol(lv-1)+sol(lv-2);
}

int main()
{
    int n; cin >> n;
    ll ans = sol(n+1);
}
