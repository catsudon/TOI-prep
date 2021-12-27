#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
string riru;
bool vst[10009];
int memo[10009];
float op[4] = {0,1.04,1.08,1.16};
int p=0;
int llenn;

int solve(int price)
{
    int ope = p,ed = p;
    int order = -1;
    priority_queue<pii > pq; /// priority : idx     [A 3 B]  idx = '3'
    while(p<llenn)
    {
         cerr << riru[p] << " " << p << endl;
        if(riru[p] >= '1' and riru[p] <='3') pq.push({riru[p]-48,p});
        if(riru[p] == '[') {int pp = p++;memo[pp] = solve(0);}
        if(riru[p] == ']') {p++; break;}
        ed = p++;
    }
    while(pq.size())
    {
        int F = pq.top().f;
        int S = pq.top().s;
        pq.pop();
         cerr << F << " " << S << " " << price;
        float temp = memo[S-1]+memo[S+1];
        temp *= op[F];
         cerr << " " << temp << endl;
        int tmr = temp; memo[S-1] = tmr; memo[S+1] = tmr;
        price += tmr;
    }
    int mx = 0;
    for(int i=ope;i<=ed;++i) mx = max(mx,memo[i]);
    return mx;

}

int main()
{
    cin >> riru;
    riru = riru + ']';
    llenn = riru.length();
    for(int i=0;i<=10005;++i) memo[i] = 20;
    cout << solve(0);

}
