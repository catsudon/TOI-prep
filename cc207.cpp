#include<bits/stdc++.h>
using namespace std;
int dp[1009][59];
int kanojo,kinouHarem;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int pay,rent,cancel;
    cin >> pay >> rent >> cancel;
    for(int i=0;i<=1005;++i) for(int j=0;j<=55;++j) dp[i][j] = INT_MAX;
    for(int i=1;i<=n;++i)
    {
        cin >> kanojo;
        if(i==1)
        {
            for(int i=0;i<=50;++i)
            {
                dp[1][i] = pay*i + rent*i;
            }
        }
        else
        {
            for(int kinou = kinouHarem;kinou<=50;++kinou)
            {
                for(int harem = kanojo;harem<=50;++harem)
                {
                    int chg = 0;
                    if(kinou > harem)
                    {
                        chg+=(kinou-harem)*cancel;
                        chg+=rent*harem;
                    }
                    else
                    {
                        chg+=pay*(harem-kinou);
                        chg+=rent*harem;
                    }
                    chg+=dp[i-1][kinou];
            //        cerr << "day " << i << " w " << harem << " girls in harem  PAID :" << chg << endl;
                    dp[i][harem] = min(dp[i][harem],chg);
                }
            }
        }
        kinouHarem = kanojo;

    }
    int ans = INT_MAX;
    for(int i=kanojo;i<=50;++i)
    {
        cerr << dp[n][i] << " ";
        ans = min(ans,dp[n][i]);
    }
    cout << ans;

}
