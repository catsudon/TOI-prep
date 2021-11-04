#include<bits/stdc++.h>
#define f first
#define s second
#define INF 1e7
using namespace std;
using pii = pair<int,int>;
using ppp = pair<int,pii>;
int e,n,ans = INT_MAX;
const int N = 50009;
vector<pii> v[N];
stack<pii> stk;
bool vst[N];
long long sum=0;
int p[N];

int fp(int i)
{
    if(p[i]==0) return i;
    return p[i] = fp(p[i]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> e >> n;
    vector<ppp> edges;
    for(int i=1;i<=e;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        edges.push_back({c,{a,b}});
    }
    vector<ppp> strange_cases;
    sort(edges.begin(),edges.end());
    for(auto it : edges)
    {
        if(fp(it.s.s) == fp(it.s.f))
        {
            strange_cases.push_back(it);
            continue;
        }
        sum+=it.f*2;
        p[fp(it.s.s)] = fp(it.s.f);
    }
    cerr << endl << endl;
    for(auto it : strange_cases)
    {
        cerr << it.f << " "<< it.s.f << " "<< it.s.s <<endl;
    }
    cout << sum;
}

