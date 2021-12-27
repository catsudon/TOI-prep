/*
TASK: Gift.cpp
LANG: C++
AUTHOR: Sathana Laolugsanalerd
ID: 63022
*/
#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using ppp = pair<ll,pii>;
ll stsum=0,ndsum=0;
vector<ll> g;
ll vst[3009];
int main()
{
    int k,n; cin >> k >> n;
    for(int i=0;i<n;++i) { int a; cin >> a; g.push_back(a); }
    sort(g.begin(),g.end());

    vector<ppp> dif;
    for(int i=0;i<g.size();++i)
    {
        int a = i+1;
        if(a>=g.size()) continue;
        dif.push_back({abs(g[i]-g[a]),{i,a}});
    }

    sort(dif.begin(),dif.end());
    ll sum=0; int p=0;
    for(int i=0;i<=3005;++i) vst[i] = LONG_MAX;
    while(p<dif.size())
    {
        int x=dif[p].s.f;
        int y=dif[p].s.s;
        int df = dif[p].f;
        p++;
        cerr << x << " " << y << " " << df << endl;
        if(vst[x] <= df or vst[y] <=df) continue;
        vst[x] = df;
        vst[y] = df;

    }
    vector<ll> fin;
    for(int i=0;i<n;++i) cerr << vst[i] << " ",fin.push_back(vst[i]);
    sort(fin.begin(),fin.end());
    for(int i=0;i<k*2;i+=2) sum+=fin[i];
    cerr << endl;
    cout << sum;

}
