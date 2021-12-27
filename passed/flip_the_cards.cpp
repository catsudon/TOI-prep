#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n,m; cin >> n >> m;
    pair<int,int> c[n+9];
    vector<bool> face(n+9,0);
    for(int i=1;i<=n;++i) cin >> c[i].f >> c[i].s;
    while(m--)
    {
        int t; cin >> t;
        for(int i=1;i<=n;++i)
        {
            if(face[i] == 0)
            {
                if(c[i].f <= t) face[i] = 1;
            }
            else
            {
                if(c[i].s <= t) face[i] = 0;
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(face[i]) cout << c[i].s ;
        else cout << c[i].f ;
        cout << endl;
    }
}
