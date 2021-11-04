#include<bits/stdc++.h>
#define N 300009
using namespace std;
vector<int> v[N];
int dp[N];
int mx=0;
int main()
{
    int n; cin >> n;
    for(int i=1;i<n;++i)
    {
        int a,b; cin >> a >> b;
        if(a>b) v[b].push_back(a);
        else    v[a].push_back(b);
    }

    for(int i=n;i>0;--i)
    {
        queue<pair<int,int> > q;
        q.push({0,i});
        int mxr = 0;
        while(!q.empty())
        {
            int F = q.front().first; // sum
            int S = q.front().second; // position
            F++;
            q.pop();

            if(i<S)
            {
                mxr = max(F-1+dp[S],mxr);
            }

            if(dp[S] >= F ) continue;

            for(auto it : v[S]) q.push({F,it});

        }
        dp[i] = mxr;
        mx = max(mx,dp[i]);
    }
    cout << mx+1;

}
