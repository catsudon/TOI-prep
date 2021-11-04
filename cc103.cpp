#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii =pair<int,int>;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,p; cin >> n >> p;int nn = n;
    vector<pii> v;
    while(n--)
    {
        int l,r; cin >> l >> r; if(l>r) swap(l,r);
        v.push_back({l,1});
        v.push_back({r+1,-1});
    }
    sort(v.begin(),v.end());

    int cnt = 0;
    int L,R;
    bool st=1;
    for(auto it : v)
    {
        if(st==0){ R=it.f-1; break;}
        if(it.s ==  1) cnt++;
        if(cnt == nn and st)
        {
            L = it.f,st=0;
            continue;
        }
        if(it.s == -1)
        {
            cout << -1; return 0;
        }
    }

    //cout << L << ' ' << R;
    if(p < L) cout << L-p;
    else if(p>=L and p<=R) cout << 0;
    else if(p>R) cout << p-R;


}
