#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        bool ok = true;
        ll r,s,p; cin >> r >> s >> p;
        ll sum = (ll)r+(ll)p+(ll)s;
        if(r==0 and s>1) ok=0;
        if(p==0 and r>1) ok=0;
        if(s==0 and p>1) ok=0;
        ok ? cout << "YES\n" : cout << "NO\n";
    }
}
