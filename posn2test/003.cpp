/*
TASK: PublicHealthNetwork.cpp
LANG: C++
AUTHOR: Sathana Laolugsanalerd
ID: 63022
*/
#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pll = pair<ll,int>;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,e; cin >> n >> e;
    vector<int> v[n+9];
    vector<ll>  tmr(n+9,0);
    vector<bool> vst(n+9,false);
    for(int i=0;i<n;++i)
    {
        ll a,b,c; cin >> a >> b >> c;
        tmr[a] = max((ll)1,c-b); // lim - infected
    }
    while(e--)
    {
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    ll sum = 0;
    priority_queue<pll,vector<pll>,greater<pll> > pq; //cost : destination
    pq.push({0,0});
    while(pq.size())
    {
        ll F = pq.top().f;
        int S = pq.top().s;
        pq.pop();
        if(vst[S]) continue;
        vst[S] = true;
        sum+=F;

        for(auto it : v[S])
        {
           if(!vst[it]) pq.push({tmr[S]+tmr[it],it});
        }
    }

    cout << sum;
}

