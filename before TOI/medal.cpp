#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n ;
    vector<ll> p(n);
    vector<ll> s(n);

    for(int i=0;i<n;++i) cin >> p[i];
    for(int i=0;i<n;++i) cin >> s[i];

    sort(p.begin(),p.end());
    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());
    vector<ll> ans(n);

    for(int i=0;i<n;++i) ans[i] = p[i]+s[i];

    sort(ans.begin(),ans.end());
    cout << abs(ans.front() - ans.back());
}
