#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using pbb = pair<bool,bool>;
using bbbb = pair<pbb,pbb>; /// x m a s
const ll INF = 2e11;
vector<pll> v[50009];
ll cst1[50009];
ll dp[50009][16]; /// node : x : m : a : s
short fuck[150];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fuck['X'] = 1; fuck['M'] = 2;
    fuck['A'] = 4; fuck['S'] = 8;
    int n,e; cin >> n >> e;
    string satan; cin >> satan; // wait...
    string cards; cin >> cards;
    cards = " " + cards;
    while(e--)
    {
        int a,b,c; cin >> a >> b >> c;
        v[a].emplace_back(c,b);
        v[b].emplace_back(c,a);
    }

    for(int i=0;i<=n;++i)
        for(int a=0;a<16;++a)
            dp[i][a] = INF;
    for(int i=0;i<=n;++i) cst1[i] = INF;

    priority_queue<pll,vector<pll>,greater<pll> > pq; /// cost : pos
    pq.push({0,n});
    while(pq.size())
    {
        ll F = pq.top().f;
        ll S = pq.top().s;
        pq.pop();
        if(cst1[S] != INF) continue;
        cst1[S] = F;
      //  cerr << F << " " << S << endl;
        for(auto it : v[S])
        {
            if(cst1[it.s] > F+it.f)
            pq.push({F+it.f,it.s});
        }
    }

    priority_queue<pair<pll,short>,vector<pair<pll,short> > ,greater< pair<pll,short> > > q; /// cost : pos   ::  x m a s
    short coef = 0;
    for(auto it : satan) coef += fuck[it];
    cerr << endl << endl << coef << endl;
    q.push({{0,1},coef});

    while(q.size())
    {
        ll cost = q.top().f.f;
        ll pos  = q.top().f.s;
        short jordi = q.top().s;
        q.pop();
        jordi |= fuck[cards[pos]];
        if(dp[pos][jordi] <= cost) continue;
        dp[pos][jordi] = cost; /// may implement more (memoize for lower class   ex (0 1 1 0) can be used for (0 0 1 0))

      //  cerr << cost << " " << pos << " " ;
      //  short polla = jordi;
      //  while(polla)
      //  {
      //      cerr << polla%2; polla/=2;
      //  }
      //  cerr << endl;
        for(auto it : v[pos])
        {
            if(dp[it.s][jordi] > it.f+cost)
            q.push({{cost+it.f,it.s},jordi});
        }
    }


    ll mn = INF;
    for(int i=1;i<=n;++i)
    {
 //       cerr << a << " " << b << " " << c << " " << d << " ";
   //     cerr << dp[i][a][b][c][d] << endl;
        mn = min(mn,dp[i][15]+cst1[i]);
    }

    cout << mn;



}
