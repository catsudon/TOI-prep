#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int k,n; cin >> k >> n;
    vector<ll> g;
    for(int i=0;i<n;++i)
    {
        int a; cin >> a;
        g.push_back(a);
    }
    sort(g.begin(),g.end());
    int llenn = g.size();
    for(int i=0;i<llenn;++i) g.push_back(g[i]);



}
