#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> t1(n),t2(n);
    for(int i=0;i<n;++i) cin >> t1[i];
    for(int i=0;i<n;++i) cin >> t2[i];

    int sum = 0;
    for(int i=0;i<n;++i)
    {
        sum+= abs(t1[i]-t2[i]);
    }
    cout << sum;
}
