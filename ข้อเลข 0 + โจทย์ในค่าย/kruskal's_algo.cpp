#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
int parent[9990];
int find_parent(int n)
{
    if(parent[n]==0) return n;
    else{
        return parent[n] = find_parent(parent[n]);
    }
}

int main()
{
    int n,e;
    cin >> n >> e;
    vector<pair<int,pii> > v;
    for(int i=0;i<e;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        v.push_back({c,{a,b}});
    }
    sort(v.begin(),v.end());
    int sum=0;
    for(auto it : v)
    {
        int w = it.f;
        int F = find_parent(it.s.f);
        int S = find_parent(it.s.s);
      //  cout << w << " " << F << " " << S << endl;
        if(F!=S)
        {
        sum+=w;
        parent[find_parent(F)] = find_parent(S);
        }
    }
    cout << sum;
}
