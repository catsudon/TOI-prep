#include<bits/stdc++.h>
using namespace std;
int l[100009];
int o[100009];
int v[100009];
int e[100009];
int lo[100009];
int lov[100009];
int love[100009];

int main()
{
    int n; cin >> n;
    string rabu; cin >> rabu;
    for(int i=1;i<=n;++i)
    {
        int idx = i-1;
        l[i]=l[i-1];
        o[i]=o[i-1];
        v[i]=v[i-1];
        e[i]=e[i-1];
        if(rabu[idx] == 'L') l[i]++;
        if(rabu[idx] == 'O') o[i]++;
        if(rabu[idx] == 'V') v[i]++;
        if(rabu[idx] == 'E') e[i]++;
    }

    cerr << "L " ; for(int i=1;i<=n;++i) cerr << l[i] << " ";
    cerr << "\nO " ; for(int i=1;i<=n;++i) cerr << o[i] << " ";
    cerr << "\nV " ; for(int i=1;i<=n;++i) cerr << v[i] << " ";
    cerr << "\nE " ; for(int i=1;i<=n;++i) cerr << e[i] << " ";
    cerr << "\n";

    for(int i=1;i<=n;++i)
    {
        int idx = i-1;
        lo[i] = lo[i-1];
        if(rabu[idx] == 'O') lo[i]+=l[i];
    }

    for(int i=1;i<=n;++i)
    {
        int idx = i-1;
        lov[i] = lov[i-1];
        if(rabu[idx] == 'V') lov[i]+=lo[i];
    }

    for(int i=1;i<=n;++i)
    {
        int idx = i-1;
        love[i] = love[i-1];
        if(rabu[idx] == 'E') love[i]+=lov[i];
    }

    cerr << "LO   " ; for(int i=1;i<=n;++i) cerr << lo[i] << " ";
    cerr << "\nLOV  " ; for(int i=1;i<=n;++i) cerr << lov[i] << " ";
    cerr << "\nLOVE " ; for(int i=1;i<=n;++i) cerr << love[i] << " ";
    cerr << "\n";


    int q; cin >> q;
    while(q--)
    {
        int a,b; cin >> a >> b;
        int coef = l[a-1];
        if(coef == 0 ) cout << 0 << endl;
        else
        cout << (love[b] - love[a-1])/coef << endl;
    }
}
