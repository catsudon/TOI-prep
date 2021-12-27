#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
bool tme[10009];
int main()
{
    int n; cin >> n;
    vector<pair<int,pair<int,int> > > v;
    for(int i=0;i<n;++i)
    {
        int s,e;  cin >> s >> e;
        int length = e-s;
        v.push_back({length,{s,e}});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i)
    {
        int x=1;
        for(int j=v[i].s.f;j<=v[i].s.s;++j)
        {
            if(tme[j]=false) tme[j] = true;
            else if(tme[j])
            {
                x=0;
                for(int k=j;k>=v[i].s.f;--k) tme[k]=false;
                break;
            }
        }
        if(x) cout << v[i].s.f << "-" << v[i].s.s << " ";
    }
}
