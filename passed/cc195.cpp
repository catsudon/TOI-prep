#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin >> v[i];

    sort(v.begin(),v.end());
    for(int i=1;i<n;++i) v[i]-=i; // -lemon lukP kicked before

    for(int i=1;i<=k;++i)
    {
        int a; cin >> a;
        int pls = upper_bound(v.begin(),v.end(),a) - v.begin();
        cout << a+pls << " ";

    }


}
