#include<bits/stdc++.h>
using namespace std;
int cnt[10009];
int main()
{
    int n; cin >> n;
    while(n--)
    {
        int a; cin >> a; cnt[a]++;
    }
    int mx=0;
    vector<int> v;
    for(int i=0;i<=10001;++i)
    {
        if(cnt[i] > mx)
        {
            mx = cnt[i];
            v.clear();
            v.push_back(i);
        }
        else if( cnt[i] == mx) v.push_back(i);
    }
    for(auto it : v) cout << it << " ";
}
