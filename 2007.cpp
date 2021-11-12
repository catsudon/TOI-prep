#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll legend = 98765431;
const ll legenz = 9876531;
ll h[300];
ll ans=0;
int main()
{
    string a,b;
    int len,llenn; cin >> len >> llenn >> a >> b;
    h['a'] = legend;
    for(int i='b';i<='z';++i)
        h[i] = h[i-1]*2;

    h['A'] = legenz;
    for(int i='B';i<='Z';++i)
        h[i] = h[i-1]*2;

    ll target = 0;
    for(int i=0;i<len;++i) target+=h[a[i]];

    ll sum = 0;
    for(int i=0;i<len;++i) sum+=h[b[i]];
    if(sum == target) ans++;
    for(int i=len;i<llenn;++i)
    {
        sum-=h[b[i-len]],sum+=h[b[i]];
        if(sum==target) ans++;
    }

    cout << ans;
}
