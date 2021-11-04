#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n; cin >> n;
    ll sum = 1;
    for(int i=0;i<n;++i)
    {
        sum = sum*4;
    }
    cout << sum;
}
