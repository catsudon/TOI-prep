#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    char f[n],s[n];
    for(int i=0;i<n;++i) cin >> f[i];
    for(int i=0;i<n;++i) cin >> s[i];

    string key; cin >> key;

    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            vector<char> v;
            v.push_back(key[i]);
            v.push_back(f[j]);
            v.push_back(s[j]);
            sort(v.begin(),v.end());
            key[i] = v[1];
        }
        cout << key[i];
    }
}

