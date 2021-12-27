#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,op; cin >> n >> op;
    vector<pair<int,int> > v;
    int mx = 0;
    pq.push({{op,0},0});
    for(int i=1;i<=n;++i)
    {
        ll a , b;
        cin >> a >> b;
        ll point = pq.top().f.f;
        ll toki = pq.top().f.s;
        int cnt = pq.top().s;
        pq.pop();

        if(abs(point - a) <= abs(toki - b))
        {
            cerr << point << " to " << a << "     time " << toki << " to " << b << endl;
            pq.push({{a,b},cnt+1});
            mx = max(mx,cnt+1);
        }
        pq.push({{point+b,toki+b},cnt});
    }

    cout << mx;
}
