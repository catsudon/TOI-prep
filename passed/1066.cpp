#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum=0; vector<int> v; cin >> n;
    for(int i=0;i<n;++i) {int t; cin >> t; v.emplace_back(t);}
    while(v.size()>1)
    {
        int mx = 0,tomoriru = -1;
        for(int i=1;i<v.size();++i)
        {
            if(abs(v[i]-v[i-1]) > mx) mx = abs(v[i]-v[i-1]),tomoriru = i-1;
        }
        sum+=mx;
        v.erase(v.begin()+tomoriru,v.begin()+tomoriru+2);
    }
    cout << sum;

}
