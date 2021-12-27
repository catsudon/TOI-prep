#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
vector<pii> v[20009];
int bounty[20009];

int main()
{
    int round,player,x,t;
    cin >> player >> round >> x >> t;
    for(int i=0;i<player;++i) cin >> bounty[i];
    vector<pii> score(player);
    for(int i=0;i<player;++i) score[i].s = i;

    for(int r=0;r<player;++r)
    {
        for(int i=0;i<round;++i)
        {
            int a; cin >> a; v[i].push_back({a,r});
        }
    }

    for(int i=0;i<round;++i)
    {
        sort(v[i].begin(),v[i].end());
        for(int j=0;j<player;++j)
        {
            score[v[i][j].s].f -= bounty[j];
        }
    }

    sort(score.begin(),score.end());
    int p=1;
    x--;
    for(auto it : score)
    {
        cerr << it.f << " " << it.s << endl;
        if(it.s == x)
        {
            cout << p;
            if(t==2)cout << " " << -it.f;
        }
        p++;
    }

}
