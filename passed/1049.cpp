#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,pair<int,int> >;
pii best[100009]; /// idx : speed and num
int counter[10009];
bool debug=0;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;++i)
    {
        int idx,speed,line; cin >> idx >> line >> speed;
        counter[line]++;
        int bestSpd = best[counter[line]].s.f;
        int bestLin = best[counter[line]].s.s;
        if(speed > bestSpd) best[counter[line]].s.f = speed,best[counter[line]].s.s = line,best[counter[line]].f=idx;
        else if(speed == bestSpd and line < bestLin) best[counter[line]].s.s = line,best[counter[line]].f=idx;


        if(!debug) continue;

    }
  //  for(int i=1;i<=3;++i) cout << " >> best of round " << i << " " << best[i].s << endl;
    int p = 1;
    while(1)
    {
        if(best[p].f == 0) break;
        cout << best[p++].f << endl;
    }


}
