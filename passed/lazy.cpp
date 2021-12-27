#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> > mp;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,q; cin >> n >> q;
    for(int i=1;i<=n;++i)
    {
        int a; cin >> a;
        mp[a].emplace_back(i);
    }
    while(q--)
    {
        int l,r,c; cin >> l >> r >> c;
        int sum = 0;
        int al = lower_bound(mp[c].begin(),mp[c].end(),l)-mp[c].begin();
        int ar = upper_bound(mp[c].begin(),mp[c].end(),r)-mp[c].begin();
    // cerr << c << " pos list ";   for(auto it : mp[c]) cerr << it << " "; cerr << endl;
      //  cerr << "    " << al << " " << ar << " \n";
        cout << ar-al << endl;
    }
}
