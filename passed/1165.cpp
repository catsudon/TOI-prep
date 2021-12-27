#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll gcd;
    int n; cin >> n >> gcd; n--;
    while(n--)
    {
        ll a; cin >> a;
        gcd = __gcd(gcd,a);
    }
    set<ll> st;
    for(ll i=1;i*i<=gcd;++i)
    {
        if(gcd%i == 0) st.insert(i);
    }

    set<ll> st2;
    for(auto it : st) st2.insert(gcd/it);

    for(auto it : st2) st.insert(it);

    cout << st.size();

}
