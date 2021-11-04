#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<pii,bool> > v(n);

    for(int i=0;i<n;++i)
    {
        cin >> v[i].f.f >> v[i].f.s;
        v[i].f.s *= -1;
        v[i].s = true;
    }

    sort(v.begin(),v.end());
    int ynow = 0,mxx = v[n-1].f.f;
    for(int i=n-1;i>=0;--i)
    {
        int F = v[i].f.f;
        int S = -v[i].f.s;
        ynow = max(ynow,S);
        if(mxx > F and ynow > S)
            v[i].s = false;
    }

    for(int i=0;i<n;++i)
    {
        if(v[i].s) cout << v[i].f.f << " " << -v[i].f.s << "\n";
    }
}
