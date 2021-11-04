#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
vector<pii> v[100009];
int vst[100009];
int getto[100009];
int op,e,k;
bool havek=0,havee=0;
int havek_pnt=0,havek_cost=INT_MAX;
int havee_pnt=0,havee_cost=INT_MAX;

bool oneway = false;

int test(bool vstk, bool vste , int cnt,int pos,int parent)
{
    if(pos == k )vstk=1;
    if(pos == e )vste=1;
    if(vstk and vste) oneway = 1;
    int moved = false;
    for(auto it : v[pos])
    {
        if(it.s == parent) continue;
        moved = 1;

    }
    if(!moved) ans = cnt
}



int main()
{
    int n; cin >> n;
    for(int i=1;i<n;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    for(int i=1;i<=n;++i) cin >> getto[i];
    cin >> op >> e >> k;
    int coef=0;
    for(auto it : v[op])test(0,0,getto[op] - it.f,it.s,op);
    if(oneway) {cout << ans; return 0;}

}
