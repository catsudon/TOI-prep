#include<bits/stdc++.h>
using namespace std;
const int INF = 1e7;
short dp[50002][27];
int main()
{
    string s; cin >> s;
    int llenn = s.length();
    if(llenn == 1)
    {
        cout << 0; return 0;
    }
    int truemin = INF;
    for(int it=1;it<llenn;++it)
    {
        if(llenn%it!=0) continue;
        for(int i=0;i<it;++i) for(int j=0;j<26;++j) dp[i][j] = 0;
        int p=0,sum=0;
        for(int i=0;i<llenn;++i)
        {
            dp[p%it][s[i]-'a']++;
            sum++;
            p++;
        }
        int realsum=sum;;
        for(int j=0;j<it;++j)
        {
            int mx=0;
            for(int i=0;i<26;++i)
            {
                mx = max(mx,(int)dp[j][i]);
            }
            realsum-=mx;
      //      cerr << sum << " " << llenn/it << endl;
        }
        truemin = min(truemin,realsum);

     //   for(int j=0;j<it;++j){ for(int i=0;i<26;++i) cerr << dp[j][i] << " "; cerr << endl;}
    }
    cout << truemin;
}
