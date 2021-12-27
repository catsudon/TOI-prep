#include<bits/stdc++.h>
using namespace std;
int n,m;
map<vector<int>,bool> mp;
int main()
{
    cin >> n >> m;
    vector<int> v[m];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            {
                int a; cin >> a;
                v[j].push_back(a);
            }
    }
    for(int i=0;i<m;++i) mp[v[i]]= false;

    vector<int> w[m];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            {
                int a; cin >> a;
                w[j].push_back(a);
            }
    }

    for(auto it : w)
    {
        for(auto ti : v)
        {
            if(ti==it) mp[it] = true;
        }
    }

    for(auto it : mp) if(it.second==false) {cout << "NO";return 0;}
    cout << "YES";
}
