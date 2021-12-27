#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    long long sum = 0;
    while(n--)
    {
        int a,b,c; cin >> a >> b >> c;
        a*=b;
        sum+=(ll)a*(ll)c;
    }
    cout << sum;

}
