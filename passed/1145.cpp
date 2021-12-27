#include<bits/stdc++.h>
#define f first
using namespace std;
using ll = long long;
const ll legend = 98765431;
deque<char> ans;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string a[5];
    for(int i=1;i<=4;++i)
    {cin >> a[i]; a[i] = " "+a[i];}
    for(int i=1;i<=4;++i) for(auto &it : a[i]) if(it>='A' and it<='Z') it+=32;
    int llenn = max({a[1].length(),a[2].length(),a[3].length(),a[4].length()})-1;

    int l=1 , r=llenn;
    while(l<=r)
    {
        int len = (l+r)/2;
        bool ok = 0;
        ll sum[5] = {0,0,0,0,0};
        map<deque<char>,int> BIGMP;
        for(int yes=1;yes<=4;++yes)
        {
            string s = a[yes];
            map<deque<char>,int > mp;
            deque<char> dq;
            for(int i=1;i<=len;++i) dq.push_back(s[i]);
            if(mp[dq]==NULL) mp[dq]=1;
            for(int i=len+1;i<s.length();++i)
            {
                dq.pop_front();
                dq.push_back(s[i]);
                if(mp[dq]==NULL) mp[dq]=1;
            }

            for(auto it : mp)
            {
          //      for(auto ti : it.f) cerr << ti ;  cerr << endl;

                if(BIGMP[it.f]==NULL) BIGMP[it.f]=1;
                else BIGMP[it.f]++;


                if(BIGMP[it.f]==3)
                {
                    ok=1 , ans = it.f;
                    break;
                }
            }


        }

   //     cerr << len << endl;

        if(ok) l=len+1;
        else r=len-1;

    }

    for(auto it : ans) cout << it;
}
