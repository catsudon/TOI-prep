#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
int n,mx=0; string s;
int dp[100009][4][4][4];

int getpts(string v)
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
    priority_queue<pair<pii,string> > pq; /// pts : idx :: last3
    string t = "000";
    pq.push({{0,0},t});
    while(pq.size())
    {
        int pts = pq.top().f.f;
        int idx = -pq.top().f.s;
        string l3 = pq.top().s;
        pq.pop();
        pts+=getpts(l3);
        if(dp[idx][l3[0]-48][l3[1]-48][l3[2]-48] >= pts) continue;
        dp[idx][l3[0]-48][l3[1]-48][l3[2]-48] = pts;
        cerr << pts << " " << idx << " " << l3 << endl;
        if(idx == n) continue;
        pq.push({{pts,-idx-1},l3});
        l3[0] = l3[1]; l3[1] = l3[2]; l3[2] = s[idx];
        pq.push({{pts,-idx-1},l3});


    }


    for(int a=0;a<4;++a) for(int b=0;b<4;++b) for(int c=0;c<4;++c) mx = max(mx,dp[n][a][b][c]);
    cout << mx;

}
