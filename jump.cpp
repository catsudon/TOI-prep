#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k; cin >> n >> k;
    vector<int> qs(60009,0);
    vector<int> point;
    for(int i=0;i<n;++i)
    {
        int a; cin >> a;
        point.push_back(a);
        qs[a]++;
    }

    for(int i=1;i<=60000;++i) qs[i] += qs[i-1];

    int mx=0;
    for(int i=0;i<n;++i)
    {
        int start = point[i];
        int stop  = min(60000,start+k);

        mx = max(mx,qs[stop]-qs[start]);
    }

    cout << mx;

}
