#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll legend = 98765321;
ll henshin[200];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    henshin['A'] = 31;
    for(int i=1;i<26;++i) henshin['A'+i] = henshin['A'+i-1]*legend;

    string a,b; cin >> a >> b;
    if(a.length() < b.length()) swap(a,b);
    for(int len = b.length();len>=1;--len)
    {
        unordered_map<ll,bool> mp;
        ll suma = 0,sumb=0;
        for(int i=0;i<len;++i) suma+=henshin[a[i]];
        mp[suma]=1;
        for(int i=len;i<a.length();++i)
        {
            suma-=henshin[a[i-len]];
            suma+=henshin[a[i]];
            mp[suma]=1;
        }
        for(int i=0;i<len;++i) sumb+=henshin[b[i]];
        if(mp[sumb])
        {
            cout << len; return 0;
        }
        for(int i=len;i<b.length();++i)
        {
            sumb-=henshin[b[i-len]];
            sumb+=henshin[b[i]];
            if(mp[sumb]){cout << len;return 0;}
        }
    }
    cout << 0;
}
