#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll legend = 98765431;
bool ok = 0; int ans = -1;

int main()
{
    int len,k; string s; cin >> len >> k >> s;

    if(k<=1) {cout << len; return 0;}
    int l=1,r=len/2+1;
    while(l<=r)
    {
        int sublen = (l+r)/2;
        ok = 0;
        unordered_map<ll,int> mp;
        ll sum = 0;
        ll mem = 1;
        for(int i=0;i<sublen;++i)
        {
            sum*=legend;
            sum+=s[i];
            if(i!=0) mem*=legend;
        }
        mp[sum] = 1;
        int temp = 0;
        for(int i=sublen;i<len;++i)
        {
            sum -= mem* s[i-sublen];
            sum *= legend;
            sum += s[i];

            if(mp[sum] == NULL) mp[sum] = 1;
            else temp = ++mp[sum];

            if(temp >= k ) ok = 1,ans=max(ans,sublen);
        }

        if(ok)
        {
            l = sublen+1;
        }
        else
        {
            r = sublen-1;
        }
    }

    cout << ans;



}
