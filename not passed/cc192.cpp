#include<bits/stdc++.h>
using namespace std;
const int N = 5009;
int dp[2][N]; // minimum change

int a[N];
int b[N];

int mx = 0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int A,B,k; cin >>  A >>  B >> k;
    for(int i=1;i<=A;++i) cin >> a[i];
    for(int i=1;i<=B;++i) cin >> b[i];

 //   for(int i=0;i<=5000;++i) dp[i][0] = 69696969;
 cerr << endl;
    dp[0][0] = 69696969;
    dp[0][1] = 69696969;

    for(int i=1;i<=A;++i)
    {
        int now = i%2;
        int mae = !now;
        for(int j=1;j<=B;++j)
        {

            if(a[i] == b[j]) dp[now][j] = dp[mae][j-1];
            else dp[now][j] = min(dp[mae][j-1]+1 , INT_MAX);

            cerr << dp[now][j] << ' ' ;
           // cerr << i << ' ' << j << endl;
        }
        cerr << endl;
    }


    cout << mx;

}

