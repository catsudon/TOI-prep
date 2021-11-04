#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll lbr,pkg; cin >> lbr >> pkg;
    int pwr[lbr];
    for(int i=0;i<lbr;++i) cin >> pwr[i];

    ll l=1;
    ll r=1e12;

    while(l<r)
    {
        ll mid = (l+r)/2;
        ll sum = 0;
        for(int i=0;i<lbr;++i) sum+=mid/pwr[i]; // in [mid] amount of time labor[number i] can do this amount of work
        if(pkg > sum) l = mid+1;
        else if(pkg <= sum) r = mid;

        //cout << l << " " << r << " " << sum << endl;
    }

    cout << l;


}
