#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using dt = pair<pii,int>;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,sum=0; cin >> n;
    vector<dt> v(n);
    for(int i=0;i<n;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[i] = {{a,b},c};
    }
    sort(v.begin(),v.end());

    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            int xx = v[i].f.f-v[j].f.f;
            if(abs(xx) > 20) break;
            xx*=xx;
            int yy = v[i].f.s-v[j].f.s;
            yy*=yy;
            int rr = v[i].s+v[j].s;
            rr*=rr;
            if(xx+yy < rr) sum++;
        }
    }
    cout << sum;
}
