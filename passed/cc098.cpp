#include<bits/stdc++.h>
using namespace std;
int g[1000009]; // grow
int last[1000009];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,m; cin >> n >> m;
    int cnt = 0;
    for(int i=1;i<=n;++i) cin >> g[i];
    for(int day=1;day<=m;++day)
    {
        int a; cin >> a;
        if(day - g[a] >= last[a])
        {
            cnt++; last[a] = day;
        }

        day++;
    }
    cout << cnt;


}
