#include<bits/stdc++.h>
using namespace std;
using ll = long long;
set<int> s;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m,q;
    cin >> n >> m >> q;

    for(int i=0;i<m;++i)
    {
        int op,ed; cin >> op >> ed;
        if(s.find(op) != s.end()) s.erase(op);
        else s.insert(op);
        if(s.find(op+ed) != s.end()) s.erase(op+ed);
        else s.insert(op+ed);
    }

    s.insert(1);
    s.insert(n+1);

    for(int i=0;i<q;++i)
    {
        int t; cin >> t;
        auto ed = s.upper_bound(t);
        auto temp = ed--;
        cout << *(temp) - *(ed);
        cout << endl;
    }
}
