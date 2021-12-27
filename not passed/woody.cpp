#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e15;
struct data
{
  int x,y;
  ll batt;
};
int n,X,Y;
struct data a[1009];
ll dp[1009];
ll dp2[1009];
ll mn = INF;

void perm(int lv , int sumx , int sumy , ll c , bool pick)
{
    if(lv == n+1)
    {
        if( sumx >= X and sumy >= Y ) mn = min(mn,c);
        return ;
    }
    if(pick) sumx+=a[lv].x , sumy+=a[lv].y , c+=a[lv].batt;
  //  cerr << lv << ' ' << sumx << ' ' << sumy << ' ' << c << ' ' << pick << endl;
    perm(lv+1,sumx,sumy,c,0);
    perm(lv+1,sumx,sumy,c,1);

}

void sol()
{
    perm(1,0,0,0,0); // level 1 : sumx : sumy : sumcost : dontpick
    perm(1,0,0,0,1);
    if(mn == INF) cout << -1;
    else cout << mn;

}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> X >> Y;
    for(int i=1;i<=n;++i)
    {
        int t;
        cin >> a[i].x >> a[i].y >> a[i].batt;
    }

    for(int i=1;i<=700;++i) dp[i] = INF , dp2[i] = INF;

    if(n<=20)
    {
        sol();
        return 0;
    }

    dp[0] = 0;
    for(int i=1;i<=n;++i)
    {
        int x = a[i].x;
        ll cost = a[i].batt;
        for(int j=500;j-x>=0;--j)
        {
            dp[j] = min({dp[j] , dp[j-x]+cost , dp[j+1]});
        }
    }



  //  for(int i=1;i<=X;++i) cerr << dp[i] << ' ';

    if(dp[X] != INF)
    cout << dp[X];
    else cout << -1;


}
