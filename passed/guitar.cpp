#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using ppp = pair<pair<ll,int>,pii>;
ll tsu[309][309];
ll seq[309];
ll dp[309][309][309];
ll mn = LONG_MAX;
int n,m,k;

typedef struct data
{
  ll tired;
  int lv;
  int quota;
  int pos;
};

void sol(int lv , ll tired , int quota ,int parent)
{
    if(tired >= mn) return;
    if(lv == m)
    {mn = min(mn,tired); return ;}
    if(dp[lv][parent][quota] <= tired) return ;
    dp[lv][parent][quota] = tired;

   // cerr << lv << ' ' << tired << ' ' << parent  << endl;

    if(quota)
    {
        sol(lv+1,tired,quota-1,parent);
    }

    if(parent==0) sol(lv+1,tired,quota,seq[lv+1]);
    else sol(lv+1,tired+tsu[parent][seq[lv+1]],quota,seq[lv+1]);

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;

    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cin >> tsu[i][j];
    for(int i=0;i<=300;++i) for(int j=0;j<=300;++j) for(int k=0;k<=300;++k) dp[i][j][k]=LONG_MAX;
    for(int i=1;i<=m;++i) cin >> seq[i];

    priority_queue<ppp> pq; // -tired : lv : quota : pos
    pq.push({{0,1},{k,seq[1]}});
    if(k>0) pq.push({{0,1},{k-1,0}});

    while(pq.size())
    {
        ll tired = -pq.top().f.f;
        int lv = pq.top().f.s;
        int quota = pq.top().s.f;
        int pos = pq.top().s.s;
        pq.pop();

        if(dp[lv][pos][quota] <= tired) continue;
        dp[lv][pos][quota] = tired;


        if(lv == m)
        {
            cout << tired; return 0;
        }

        if(quota)
        {
            pq.push({{-tired,lv+1},{quota-1,pos}});
        }

        if(pos==0) pq.push({{-tired,lv+1},{quota,seq[lv+1]}});
        else pq.push({{-(tired+tsu[pos][seq[lv+1]]),lv+1},{quota,seq[lv+1]}});


    }


  //  if(k>0) sol(1,0,k-1,0);
    //sol(1,0,k,seq[1]);


    //cout << mn;
}
