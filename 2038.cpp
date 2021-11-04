#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int sum = 0;
int p[300];
int fp(int i)
{
    if(p[i] == 0) return i;
    return p[i] = fp(p[i]);
}

int main()
{
    int n,q;
    cin >> n >> q;
    set<pair<int,pair<int,int> > > e;
    while(q--)
    {
        int a,b,c; int vst=1,sum=0;
        cin >> a >> b >> c; e.insert({c,{a,b}});
        for(int i=1;i<=n;++i) p[i] = 0;
        for(auto it : e)
        {
            int na = it.s.f;
            int nb = it.s.s;
            if(fp(na) == fp(nb)) continue;
            p[fp(na)] = fp(nb); sum+=it.f;
            vst++;
            if(vst==n) break;
        }
        if(vst!=n) cout << -1 << endl;
        else cout << sum << endl;
    }
}
