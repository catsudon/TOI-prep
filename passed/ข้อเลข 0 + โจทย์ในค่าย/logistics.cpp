#include<bits/stdc++.h>
using namespace std;
using pcc = pair<char,char>;
map<vector<pcc>,vector<int> > mp;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    unordered_set<char> us;
    for(int i=0;i<n;++i)
    {
        vector<pcc> v,v2;
        char a,b,l;
        cin >> a >> b >> l;
        us.insert(a);
        us.insert(b);
        v.push_back({a,b});
        v2.push_back({b,a});
        mp[v].push_back(l);
        mp[v2].push_back(l);
    }
    for(int i=97;i<=123;++i)
    {
        if(us.find(char(i))!=us.end())
        for(int j=i+1;j<=123;++j)
        {

            if(mp[{{char(i),char(j)}}].empty()) continue;
            else
            {
                cout << mp[{{char(i),char(j)}}].size() << " ";
            }
        }
    }

}
