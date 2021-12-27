#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
pii a[100009];

int main()
{
    int n,q; cin >> n >> q;
    for(int i=1;i<=n;++i) {cin >> a[i].f; a[i].s = i; a[i].f+=a[i-1].f;}
    for(int i=1;i<n;++i)
    {
        if(a[i].f >= a[i+1].f)
        {
            a[i].f = a[i+1].f;
            a[i].s++;
        }
    }

    sort(a+1,a+n+1);
    for(int i=2;i<=n;++i) if(a[i].s < a[i-1].s) a[i].s = a[i-1].s;
    vector<int> v(n+1,0);
    for(int i=1;i<=n;++i) v[i] = a[i].f;

    for(int i=1;i<=n;++i) cerr << a[i].f << ":" << a[i].s << " ";
    while(q--)
    {
        int t; cin >> t;
        int idx = upper_bound(v.begin()+1,v.end(),t) - v.begin();
        idx--;
        cout << a[idx].s << endl;

    }
}
