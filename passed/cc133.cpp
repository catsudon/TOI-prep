#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;

    while(q--)
    {
        int mn = INT_MAX;
        int n,k; cin >> n >> k; // must be >= k
        vector<pii> v;
        for(int i=1;i<=n;++i)
        {
            int a,b; cin >> a >> b;
            v.push_back({b,a});
        }
        sort(v.begin(),v.end());

        for(int i=0;i<v.size();++i)
        {
            for(int j=v.size()-1;j>i;--j)
            {
                if(v[j].f - v[i].f < k) break;
                mn = min(mn , abs(v[i].s - v[j].s) );
            }
        }

        if(mn!=INT_MAX)cout << mn << endl;
        else cout << -1 << endl;
    }
}
