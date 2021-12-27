#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long sum = 0;
    int n; cin >> n;
    vector<int> v;
    for(int i=0;i<n;++i) for(int j=0;j<n;++j)
    {
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int t = 1;
    int cnt = 1;
    for(auto it : v)
    {
        t*=it;
        cnt++;
        if(cnt == 5)
        {
            cerr << t << endl;
            cnt = 1,sum+=t,t=1;
        }
    }
    cout << sum;
}
