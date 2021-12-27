#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<long long> a(n*2);
    for(int i=0;i<n*2;++i)
    {
        cin >> a[i];
    }

    sort(a.begin(),a.end());
    long long sum = 0;
    for(int i=0;i<n;++i)
    {
        sum += a[i] * a[n*2-1-i];
    }

    cout << sum;
}
