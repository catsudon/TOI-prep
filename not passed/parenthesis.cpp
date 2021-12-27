#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
const ll INF = 1e15;
ll dp[100009] , parent[100009] , dp2[100009];
ll must_have_more_than[100009];
vector<int> v[100009];
string icon;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,op,ed; cin >> n >> op >> ed;

    for(int i=1;i<n;++i)
    {
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);

        dp[i] = INF;
        dp2[i] = INF;
    }
    dp[n]=INF; dp2[n]=INF;
    cin >> icon;  icon = " " + icon;

    queue<pair<pair<int,ll>,ll> > q;
    q.push({{op,0},-1});

    while(q.size())
    {
        int pos = q.front().f.f;
        ll paren = q.front().f.s;
        ll  p   = q.front().s;
        q.pop();

        if(paren!=-INF)
        if(icon[pos] == '(') paren++;
        else paren--;

        if(paren < 0 ) // error
        {
            paren = -INF;
        }

        dp[pos] = paren;
        parent[pos]  =p;
//        cerr << pos << ' ' << paren;

        for(auto it : v[pos])
        {
            if(dp[it]==INF) q.push({{it,paren},pos});
        }
    }

    q.push({{ed,0},0});
    while(q.size())
    {
        int pos = q.front().f.f;
        ll paren = q.front().f.s;
        ll  must   = q.front().s;
        q.pop();

        if(icon[pos] == '(') paren--;
        else paren++;

        must = min(must,paren);
        dp2[pos] = -paren;
        must_have_more_than[pos] = -must;
  //      cerr << pos << ' ' << paren << ' ' << must << endl;

        for(auto it : v[pos])
        {
            if(dp2[it]==INF) q.push({{it,paren},must});
        }
    }

  //      for(int i=1;i<=n;++i) cerr << dp[i] << ' '; cerr << endl;
    //    for(int i=1;i<=n;++i) cerr << dp2[i] << ' '; cerr << endl;
      //  for(int i=1;i<=n;++i) cerr << must_have_more_than[i] << ' '; cerr << endl;
    ll cnt = 0;
    for(int i=1;i<=n;++i)
    {
        int p = parent[i];
        int paren = dp[i];if(paren == -INF) continue;
        for(int j=1;j<=n;++j)
        {
            if(paren < must_have_more_than[j]) continue;
            if(dp[i]+dp2[j] == 0 )
            {
          //      cerr << i << ' ' << j << endl;
                cnt++;
            }
        }
    }

    cout << cnt;

}

