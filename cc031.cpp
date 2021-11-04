#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[10009];
int main()
{
    ll n; cin >> n;
    ll coef = n;
    ll sum = 1;

    for(int i=1;i<=n;++i)
    {
        ll l = i-1;
        ll r = n-i;
        sum+=l*r;
        sum%=909091;
        coef--;
    }

    cout << sum;


}
