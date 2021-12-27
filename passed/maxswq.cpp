#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum=0,mx=0;
    cin >> n;
    int dp[n];

    int len =0;
    int memo=0;

    int anslen,ansmemo;
    for(int i=0;i<n;++i)
    {
        int a; cin >> a;
        dp[i]=a;
        if(sum+a>0) sum+=a,len++;
        else sum = 0,memo = i+1,len=0;

        if(sum>mx) anslen = len,ansmemo = memo,mx=sum;

    }

    if(mx==0) cout << "Empty sequence";
    else
    {
        for(int i=0;i<anslen;++i)
            cout << dp[i+ansmemo] << " ";
        cout << endl << mx;
    }

}
