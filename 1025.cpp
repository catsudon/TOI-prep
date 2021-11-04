#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll lcm(ll a,ll b)
{
    ll sum = a*b;
    return sum/__gcd(a,b);
}

int main()
{
    int n,sum; cin >> n >> sum;
    for(int i=1;i<n;++i)
    {
        int t; cin >> t;
        sum = lcm(sum,t);
    }

    cout << sum;
}
