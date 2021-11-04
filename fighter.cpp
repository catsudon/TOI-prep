#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int f1 = n;
    int f2 = n;
    int dp[n*2+10];
int i=0;
    while(++i)
    {
        int a; cin >> a;
        dp[i] = a;
        if(i>2 and dp[i]%2 == dp[i-1]%2 and dp[i]%2 == dp[i-2]%2)
        {
            if(a%2==0) f1-=3;
            else f2-=3;
        }
        else
        {
            if(a%2==0) f1--;
            else f2--;
        }
      //  cout << f1 << " " << f2 << endl;
        if(f1<=0) {cout << 0 << endl << dp[i]; return 0;}
        if(f2<=0) {cout << 1 << endl << dp[i]; return 0;}


    }
}
