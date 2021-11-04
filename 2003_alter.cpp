#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
int n,mx=0; string s;
int dp[100009][4][4][4];
int getpts(deque<int> v)
{
    bool vst[4] = {0,0,0,0}; int c=0;
    for(auto it : v)
    {
        if(!vst[it-48]) c++,vst[it-48]=true;
    }
    if(vst[0]) c--;
    return c;
}
int main()
{
    cin >> n >> s;
    for(int i=0;i<n;++i)
    {
        if(s[i] == 'M') s[i] = '1';
        if(s[i] == 'F') s[i] = '2';
        if(s[i] == 'B') s[i] = '3';
    }
    for(int i=0;i<=n;++i) for(int a=0;a<4;++a) for(int b=0;b<4;++b) for(int c=0;c<4;++c) dp[i][a][b][c] = -1;
    priority_queue<pair<pii,deque<int>> > q; ///  idx : score :: mae
    deque<int> t; for(int i=0;i<2;++i) t.push_back('0'); t.push_back(s[0]);
    q.push({{0,-1},t});
    while(q.size())
    {
        deque<int> v = q.top().s;
        int idx = -q.top().f.s;
        int pts = q.top().f.f;
        q.pop();
        pts+=getpts(v);
        if(dp[idx][v[0]-48][v[1]-48][v[2]-48] >= pts) continue;
        dp[idx][v[0]-48][v[1]-48][v[2]-48] = pts;
       // cerr << idx << " " << pts << " dq : "; for(auto it : v) cerr << char(it) << " "; cerr << endl;
        mx = max(mx,pts);
        /// considering just 1 mine is OK!
        if(idx==n) continue;
        q.push({{pts,-(idx+1)},v});
        v.pop_front(); v.push_back(s[idx]);
        q.push({{pts,-(idx+1)},v});
    }
    cout << mx;
}
