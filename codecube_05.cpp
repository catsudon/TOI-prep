#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n; cin >> n;
    n--;
    long long ans; cin >> ans;
    while(n--)
    {
        long long a; cin >> a;
        ans = (ans*a)/ __gcd(ans,a);
    }
    cout << ans;
}
