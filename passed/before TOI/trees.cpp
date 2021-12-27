#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll legend = 98765431;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q=5;
    while(q--)
    {
        int n; cin >> n;
        vector<pair<int,int> > v;
        for(int i=2;i<=n;++i)
        {
            int a,b ; cin >> a >> b;
            if(a>b) swap(a,b);
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        ll chk = 0;
        for(auto it : v )
        {
            chk*=legend;
            chk+=it.first;
            chk*=legend;
            chk+=it.second;
        }



        vector<pair<int,int> > vv;
        for(int i=2;i<=n;++i)
        {
            int a,b ; cin >> a >> b;
            if(a>b) swap(a,b);
            vv.push_back({a,b});
        }
        sort(vv.begin(),vv.end());
        ll sum = 0;
        for(auto it : vv )
        {
            sum*=legend;
            sum+=it.first;
            sum*=legend;
            sum+=it.second;
        }

        sum==chk ? cout << "Y" : cout << "N";
    }

}
