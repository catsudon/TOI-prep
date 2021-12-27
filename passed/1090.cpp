#include<bits/stdc++.h>
using namespace std;
int tail[1000000];
map<int,int> mp;
long long ans = 0;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a;
    cin >> n;
    for(int i=0;i<n;++i)
    {
        int t; cin >> t;
        if(mp[t] == NULL) mp[t] = 1;
        else mp[t]++;
        tail[i] = t;
    }
    cin >> a;
    for(int i=0;i<n;++i)
    {
        int want = a-tail[i];
        if(tail[i] == want) {ans+=mp[want]-1;continue;}
        if(mp[want] == NULL) continue;
        else ans+=mp[want];

    }

    cout << ans/2;

}
