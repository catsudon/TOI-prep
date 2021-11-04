#include<bits/stdc++.h>
using namespace std;
int n,v,mx=-1;
vector<int> shop[9000];

int start(int used,int day)
{
    if(used>mx && used<=v && day==n) mx = used;
    if(used>v || day==n) return 0;
    for(auto it :shop[day])
    {
        start(used+it,day+1);
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> v;
    for(int i=0;i<n;++i)
    {
        int a;
        cin >> a;
        for(int j=0;j<a;++j) { int x;cin >> x;shop[i].push_back(x); }
    }
    start(0,0);
    cout << mx;
}
