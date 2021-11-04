#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
map<int,int> mp; /// pos : val
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,op; cin >> n >> k >> op;

    queue<pair<pii,int> > q;     /// day : val :: pos
    q.push({{1,0},op});
    int d = 0,mx=0;
    int bookpos,bookval;
    while(!q.empty())
    {
        int day = q.front().f.f;
        int val = q.front().f.s;
        int pos = q.front().s;
        q.pop();

        if(mp[pos]!=NULL and mp[pos] > val ) continue;
        mp[pos] = val;
        if(day == n+1) {mx=val;break;}
        if(day >  d  ) {cin >> bookpos >> bookval; d++;}

        if(pos+k >= bookpos and pos < bookpos) q.push({{day+1,val+bookval},bookpos});
        if(pos-k <= bookpos and pos > bookpos) q.push({{day+1,val+bookval},bookpos});
        if(pos == bookpos) q.push({{day+1,val+bookval},bookpos});
        q.push({{day+1,val},pos});
    }

    while(!q.empty())
    {
        int t = q.front().f.s;
        q.pop();
        mx = max(mx,t);
    }

    cout << mx;
}
