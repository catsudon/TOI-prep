#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int door[200009];
int p[200009];

int fp(int i)
{
    if(p[i] == 0 ) return i;
    return p[i] = fp(p[i]);
}

int main()
{
    int n,q; cin >> n >> q;
    vector<pair<int,int> > v;
    for(int i=1;i<=n;++i)
    {cin >> door[i];v.push_back({i,door[i]});}

    for(auto it : v)
    {
        if(fp(it.f) == fp(it.s) ) continue;
        p[fp(it.f)] = fp(it.s);
    }
//    for(int i=1;i<=n;++i) cout << p[i] << " " ; cout << endl;

    while(q--)
    {
        int op,ed,a,b;
        cin >> op >> ed >> a >> b;
        if(fp(a) != fp(b) and fp(op) != fp(ed) ) cout << "SURVIVE\n";
        else if(fp(op) == fp(ed))cout << "DEAD\n";
        else cout << "SURVIVE\n";
    }
}
