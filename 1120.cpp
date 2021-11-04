#include<bits/stdc++.h>
using namespace std;
int dp[1000009];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=1;i<=1000000;++i)
        for(int j=i;j<=1000000;j+=i) dp[j]++;
    int q; cin >> q;
    while(q--)
    {
        int a,b,c,d=0; cin >>a  >> b >> c;
        for(int i=a;i<=b;++i) if(dp[i]==c) d++;

        cout << d << endl;
    }

   // cout << endl << endl;
   // for(int i=1;i<=100;++i) cout << i << " " << dp[i] << endl;

}
