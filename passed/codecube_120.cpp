#include<bits/stdc++.h>
using namespace std;
const int sze = 1e6+99;
const int INF = 1e9+9;
int a[11],b[11],n,k,m,pay,chg;
int dp[sze];
int step[sze];
int x=0,y=0;
vector<int> koin;
int sabuza = INF;

int tomo(int sum)
{
    int num = step[sum];
    for(int i=0;i<k;++i) if(koin[i] == num ) a[i]++;
    if(sum-num > 0) tomo(sum-num);
}

int riru(int sum)
{
    int num = step[sum];
    for(int i=0;i<k;++i) if(koin[i] == num ) b[i]++;
    if(sum-num > 0) riru(sum-num);
}

int main()
{
    cin >> n >> m >> k; /// price , maxmoney , cointtype
    for(int i=0;i<=m;++i) dp[i] = INF;
    for(int i=0;i<k;++i)
    {
        int a; cin >> a; koin.emplace_back(a);
    }
    dp[0] = 0;
    for(int i=1;i<=m;++i)
    {
        for(auto it : koin)
        {
            int sum = i-it;
            if(sum < 0) continue;
            if(1+dp[sum] < dp[i])
            {
                dp[i] = 1+dp[sum];
                step[i] = it;
            }
        }
    }
    int mn = INF;
    for(int i=n;i<=m;++i)
    {
        int koin_dif = dp[i] + dp[i-n];
        if(koin_dif < mn)
        {
            sabuza=dp[i];
            mn = koin_dif;
            pay = i;   /// money
            chg = i-n; /// money
            x = dp[pay];
            y = dp[chg];
        }
        else if(koin_dif == mn and dp[i] < sabuza)
        {
            sabuza = dp[i];
            mn = koin_dif;
            pay = i;   /// money
            chg = i-n; /// money
            x = dp[pay];
            y = dp[chg];
        }
    }

    tomo(pay); riru(chg);
    cout << x << " " << y << endl;
    for(int i=0;i<k;++i) cout << a[i] << " " ;
    cout << endl;
    for(int i=0;i<k;++i) cout << b[i] << " " ;
    cout << endl;

   // for(int i=0;i<=m;++i) cerr << dp[i].f << " " << dp[i].s << endl;
}
