#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k; cin >> n >> k; vector<int> koto(n);
    for(int i=0;i<n;++i) cin >> koto[i];
    int sum=0; sort(koto.begin(),koto.end());
    for(int i=n-1;i>=0;i-=k) sum+=koto[i]; cout << sum;

}
