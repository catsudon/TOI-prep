#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
vector<int> lis;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    for(int i=1;i<=n;++i)
    {
        int a; cin >> a;
        if(lis.empty() or lis.back() < a)
        {
            lis.push_back(a);
        }
        else if(lis.back()==a) {}
        else
        {
            auto t = upper_bound(lis.begin() , lis.end() , a);
            if(*(t-1)!=a)*t=a;
        }

        for(auto it : lis) cerr << it << ' '; cerr << endl;
    }

    cout << n-lis.size();


}
