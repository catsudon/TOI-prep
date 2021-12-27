#include<bits/stdc++.h>
using namespace std;
using ll = long long;
unordered_map<ll,int> mp;
int main()
{
    // idea
    // 1   2  3  4  5  6  7  8  9 10  11  12 13 14 15
    // R   O  R  R  O  O  R  O  O  R   O  O  O  R  O
    // -3 -2 -5 -8 -7 -6 -9 -8 -7 -10 -9 -8 -7 -10 -9
    int n,k; cin >> n >> k;
    string panyaon; cin >> panyaon;
    ll sum = 0;
    int mx = 0;
    int p=0;
    for(auto it : panyaon)
    {
        p++;
        if(it == 'R') sum+=k;
        else sum--;
        if(mp[sum] == 0 and sum!=0) mp[sum] = p;
        else mx = max(mx,p-mp[sum]);
    }
    cout << mx;
}
