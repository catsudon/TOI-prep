#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    set<string> a;
    while(n--)
    {
        string t; cin >> t; a.insert(t);
    }
    for(auto it : a) cout << it << '\n';
}
