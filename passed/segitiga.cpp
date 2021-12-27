#include<bits/stdc++.h>
using namespace std;
int op[3][3] = {2,1,0,2,1,1,1,2,1};
bool solve()
{
    int n;
    string s;
    cin >> n >> s;
    bool dp[n][n][3];
    memset(dp,false,sizeof dp);
    for(int i=0;i<n;++i) dp[i][i][s[i]-'0'] = true;

    for(int coef=1;coef<n;++coef)
    {
        for(int i=0;i+coef<n;++i)
        {
            int lim = i+coef;
            for(int j=i;j<lim;++j)
            {
                for(int a=0;a<3;++a) for(int b=0;b<3;++b)
                {
                    if(dp[i][j][a] and dp[j+1][lim][b]) dp[i][lim][op[a][b]]=true;
                }
            }
        }
    }


    if(dp[0][n-1][0]) return true;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q=20;
    while(q--)
    {
       if(solve()) cout << "yes";
       else cout << "no";
       cout << endl;
    }
}
