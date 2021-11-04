#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> v[500009];
bool stone[500009],vst[500009];
int mx = -1;

int sol(int lv)
{
    if(vst[lv]) return 0;
    vst[lv] = 1;
    mx = max(mx,lv);

    for(auto it : v[lv]) sol(it);

    if(!stone[lv] and lv < n) sol(lv+1);
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=m;++i)
    {
        int a,b; cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i=1;i<=k;++i)
    {
        int a; cin >> a;
        stone[a] = 1;
    }

    sol(1);

    if(mx == n ) cout << 1; else cout << 0;
    if(mx!=n) cout << " " << mx;


}
