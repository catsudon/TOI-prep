#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ppp = pair<ll,pll>;
int n,m;
vector<ppp> v;
vector<pll> V[200009];
int p[200009];
bool vst[200009];

int fp(int i)
{
    if(p[i] == 0 ) return i;
    else return p[i] = fp(p[i]);
}

void krus()
{
   while(m--)
   {
       ll a,b,c; cin >> a >> b >> c;
       v.push_back({-(c-1),{a,b}});
   }

   sort(v.begin(),v.end());
   ll sum = 0;
   for(auto it : v)
   {
       ll cost = -it.f;
       ll u = it.s.f;
       ll v = it.s.s;
       if(fp(u) == fp(v)) continue;
       sum+=cost;
       p[fp(u)] = fp(v);
   }

   cout << sum;
}

void prim()
{
    priority_queue<pll> pq;
    while(m--)
    {
        ll a,b,c ; cin >> a >> b >> c;
        V[a].push_back({c-1,b});
        V[b].push_back({c-1,a});
    }
 ll sum=0;
    pq.push({0,1});
    while(pq.size())
    {
        ll cst = pq.top().f;
        ll pos = pq.top().s;
        pq.pop();

        if(vst[pos]) continue;
        sum+=cst;
        vst[pos]=1;
    //    cerr << pos << ' ' << cst << endl;
        for(auto it : V[pos])
        {
            if(!vst[it.s])
            {
        //        cerr << it.f << ' ' << it.s << endl;
                pq.push({it.f,it.s});
            }
        }
    }

    cout << sum;


}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
   cin >> n >> m;
  // krus();
   prim();

}
