#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin  >> n;
    int mn = INT_MAX;
    int mx = -mn;
    while(n--)
    {
        int a; cin >> a;
        mx = max(mx,a);
        mn = min(mn,a);
    }
    cout << mn << endl << mx;
}

