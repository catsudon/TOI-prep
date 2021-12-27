#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    int n; cin >> n;
    vector<int> lis;
    for(int i=1;i<=n;++i)
    {
        int a; cin >> a;
        if(lis.empty() or lis.back() < a)
        {
            lis.push_back(a);
            continue;
        }
        auto it = lower_bound(lis.begin(),lis.end(),a);
        *it=a;
    }
    cout << lis.size();
}
