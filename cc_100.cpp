#include<bits/stdc++.h>
using namespace std;
const int X = 1e5+9;
int qs[4][X]; // L O V E
int main()
{
    int n; string raburabu;
    cin >> n >> raburabu;
    int q; cin >> q;
    for(int i=1;i<=n;++i)
    {
        int a = i-1;
        if(raburabu[a] == 'L') qs[0][i]++;
        if(raburabu[a] == 'O') qs[1][i]++;
        if(raburabu[a] == 'V') qs[2][i]++;
        if(raburabu[a] == 'E') qs[3][i]++;
        for(int j=0;j<4;++j) qs[j][i] += qs[j][i-1];

    }
    while(q--)
    {
        int l,r; cin >> l >> r;
        int a=l-1;
        int b=r-1;
        int sum=0;
        queue<pair<pair<int,int>,char> > q; // pos : cnt
        for(int i=a;i<=b;++i) if(raburabu[i] == 'E') q.push({{i,1},'E'});

        while(!q.empty())
        {

        }



    }
}
