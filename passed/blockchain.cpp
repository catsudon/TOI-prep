#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
map<vector<pii>,int> m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,q; cin >> t >> q;

    for(int i=0;i<t;++i)
    {
        vector<pii> v;
        int n; cin >> n;
        for(int j=0;j<n-1;++j)
        {
            int a,b; cin >> a >> b;
            a>b ? v.push_back({b,a}): v.push_back({a,b});
        }
        sort(v.begin(),v.end());
   //     cerr << "TEST >> " ;
     //   for(auto it : v) cerr << it.f << " " << it.s << " : " ;
       // cerr <<endl;
        if(m[v]==NULL or m[v]==0) m[v] = 1;
        else m[v]++;
    }

    for(int i=0;i<q;++i)
    {
        vector<pii> v;
        int n; cin >> n;
        for(int j=0;j<n-1;++j)
        {
            int a,b; cin >> a >> b;
            a>b ? v.push_back({b,a}) : v.push_back({a,b});
        }

        sort(v.begin(),v.end());
     //   cerr << "TEST >> " ;
       // for(auto it : v) cerr << it.f << " " << it.s << " : " ;
       // cerr <<endl;
        if(m[v]!=NULL) cout << m[v];
        else cout << 0;
        cout << "\n";
    }

}
