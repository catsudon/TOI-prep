#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;
int main()
{
    ll r,g; cin >> r >> g;
    int gcd = __gcd(r,g);
    for(int i=1;i<=gcd;++i)
    {
        if(gcd%i==0) cout << i << " " << r/i << " " << g/i << endl;
    }
}
