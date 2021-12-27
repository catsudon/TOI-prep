#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int mx = INT_MIN;
    int mn = INT_MAX;
    int n; cin >> n;
    while(n--)
    {
        int a; cin >> a;
        mx = max(mx,a); mn = min(mn,a);
    }
    cout << mx << "\n" << mn;
}
