#include<bits/stdc++.h>
using namespace std;
vector<int> dp(1000009,-1);
int a,b,c;

void riru(int n)
{
    int nn = n,cnt = 0;
    nn++; nn/=2;
    for(int i=nn;i>=1;--i)
    {
        if(n%i) continue;
        if(dp[i] == -1) riru(i);
        cnt+=dp[i];
   //     cerr << i << " " << dp[i] << " << \n";
    }
    dp[n] = cnt+1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    dp[1] = 1; dp[2] = 2;
    while(q--)
    {
        int cnt = 0;
        cin >> a >> b >> c;
        for(int i=a;i<=b;++i)
        {
            if(dp[i] == -1) riru(i);
            if(dp[i] == c )
            cnt++;
        }
        cout <<  cnt << endl;
    }
}
