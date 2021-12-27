#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
int tomo[1009];
int riru[1009];
pii dp[1009][1009]; // day : time


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int lim,n; cin >> lim >> n;

    for(int i=1;i<=n;++i) cin >> tomo[i];
    for(int i=1;i<=n;++i) cin >> riru[i];

    for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) dp[i][j] = {INT_MAX,INT_MAX};

    priority_queue<pair<pii,pii> , vector<pair<pii,pii> > , greater<pair<pii,pii > > > pq; // day : time :: task1 : task2
    pq.push({{0,0},{0,0}});
    while(pq.size())
    {
        int day = pq.top().f.f;
        int tme = pq.top().f.s;
        int tmr = pq.top().s.f;
        int rru = pq.top().s.s;
        pq.pop();

        if(day > dp[tmr][rru].f) continue;
        if(day == dp[tmr][rru].f and tme >= dp[tmr][rru].s) continue;
        dp[tmr][rru] =  {day,tme};


        if(tomo[tmr+1]+tme <= lim ) pq.push({{day,tme+tomo[tmr+1]},{tmr+1,rru}});
        else pq.push({{day+1,tomo[tmr+1]},{tmr+1,rru}});

        if(riru[rru+1]+tme <= lim ) pq.push({{day,tme+riru[rru+1]},{tmr,rru+1}});
        else pq.push({{day+1,riru[rru+1]},{tmr,rru+1}});

    }

    cout << dp[n][n].f+1 << endl << dp[n][n].s;


}
