#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> ok;
    for(int i=0;i<n;++i)
    {
        int t; cin >> t;
        auto it = upper_bound(ok.begin(),ok.end(),t);
        if(it==ok.end()) ok.emplace_back(t);
        else *it = t;
    }
    cout << n-ok.size();
}
