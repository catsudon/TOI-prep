#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin >> v[i];
    if(n==1)
    {
        cout << "no";
        return 0;
    }
    sort(v.begin(),v.end());
    if(v[0]+v[1] > v[n-1]) cout << "no";
    else cout << "yes";
}
