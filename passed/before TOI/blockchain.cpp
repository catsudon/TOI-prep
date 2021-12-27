#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
map<vector<pii>,int> mp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,q; cin >> t >> q;

    while(t--)
    {
        vector<pii> v;
        int n; cin >> n; n--;
        while(n--)
        {
            int a,b; cin >> a >> b;
            if(a>b) swap(a,b);
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        if(mp[v]==NULL or mp[v]==0) mp[v] = 1;
        else mp[v]++;
    }
    while(q--)
    {
        vector<pii> v;
        int n; cin >> n; n--;
        while(n--)
        {
            int a,b; cin >> a >> b;
            if(a>b) swap(a,b);
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        mp[v] == NULL ? cout << 0 : cout << mp[v];
        cout << "\n";
    }
}
