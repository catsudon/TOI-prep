#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    set<int> a,b;
    for(int i=1;i*i<=n;++i)
    {
        if(n%i==0) a.insert(i);
    }
    for(auto it : a) b.insert(n/it);
    for(auto it : b) a.insert(it);
    //sort(a.begin(),a.end());
    for(auto it:a) cout << it << ' ';
}
