#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;

pii a[100009];
int cost[100009];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,q; cin >> n >> q;

    for(int i=1;i<=n;++i)
    {
        cin >> a[i].f;
        a[i].f+=a[i-1].f;
        a[i].s=i;

        cost[i] = INT_MAX;
    }
    vector<pii> v;
    for(int i=n;i>1;--i)
    {
        if(a[i].f <= a[i-1].f ) a[i-1].f=a[i].f,a[i-1].s=a[i].s;
    }

    sort(a+1,a+1+n);

    while(q--)
    {
        int p; cin >> p;
        int idx = lower_bound(a+1,a+1+n,make_pair(p,-1))-a;

        if(a[idx].f == p )cout << a[idx].s;
        else cout << a[idx-1].s;

        cout << endl;
    }






}
