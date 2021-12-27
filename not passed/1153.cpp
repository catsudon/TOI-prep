#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ppp = pair<int,pii>;
int dp[1009][1009];
vector<pair<int,int> > jone[1009];
int Free[1009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int copycat = n;
    while(copycat--)
    {
        int a,b,c ; cin >> a >> b >> c;
        jone[a].push_back({c,b});
    }
    int bef = -1;
    for(int i=1000;i>=1;--i)
    {
        if(jone[i].size()==0) continue;
        Free[i] = bef;
        bef = i;
    }
    Free[0] = bef;
    for(int i=0;i<=n;++i)for(int j=0;j<=n;++j) dp[i][j]= -1;
    queue<ppp> pq; // money  ::  me : bestofurendo
    pq.push({0,{0,0}});
    int mx = 0;
    while(pq.size())
    {
        int sum = pq.front().f;
        int p1    = pq.front().s.f;
        int p2    = pq.front().s.s;
        pq.pop();
        mx = max(mx,sum);
        int nextTime = p1;
        if(jone[p1].size()==0) nextTime = Free[p1];
        for(auto it : jone[nextTime])
        {
            int get = it.f;
            int go  = it.s;
            if(dp[go][p2] < sum+get ) // p1 go
            {
                dp[go][p2] = sum+get;
                pq.push({sum+get,{go,p2}});
            }
            if(Free[p1]!=-1)
            if(dp[Free[p1]][p2] < sum ) // p1 stay till next thief come
            {
                dp[Free[p1]][p2] = sum;
                pq.push({sum,{Free[p1],p2}});
            }
        }
        nextTime = p2;
        if(jone[p1].size()==0) nextTime = Free[p2];
        for(auto it : jone[nextTime])
        {
            int get = it.f;
            int go  = it.s;
            if(dp[p1][go] < sum+get ) // p2 go
            {
                dp[p1][go] = sum+get;
                pq.push({sum+get,{p1,go}});
            }
            if(Free[p2]!=-1)
            if(dp[p1][Free[p2]] < sum ) // p2 stay till next thief come
            {
                dp[p1][Free[p2]] = sum;
                pq.push({sum,{p1,Free[p2]}});
            }
        }
    }
    cout << mx;
}
