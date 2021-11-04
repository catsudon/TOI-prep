#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
vector<pair<int,pair<int,int> > > edges;
int parent[200009];
int find(int n)
{
    if(parent[n]==0) return n;
    else return parent[n] = find(parent[n]);
}

int merge(int f,int s)
{
    int x = find(f);
    int y = find(s);
    parent[x] = y;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,e; cin >> n >> e;
    edges.resize(e);
    for(int i=0;i<e;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edges[i] = {-c,{a,b}};
    }
    sort(edges.begin(),edges.end());
    long long int sum=0;
    for(auto edge : edges)
    {
        int w = -edge.f;
        int F = find(edge.s.f);
        int S = find(edge.s.s);
     //   if(F==S) continue;
     //   sum+=w-1;
        if(F!=S){merge(F,S);sum+=w-1;}
       // e--;
       // if(e==0) break;
    }
    cout << sum;
}
