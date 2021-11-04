#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ppp = pair<int,pii>;
int dp[1009][1009];
bool vst[1009][1009];
int a[1009][1009];
int main()
{
    int n;
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cin >> a[i][j];
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) dp[i][j] = -1;

    queue<ppp> q; /// ways :
}
