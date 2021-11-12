#include<bits/stdc++.h>
using namespace std;
map<unsigned long long , bool > mp;

bool prime(unsigned long long a)
{
    for(unsigned long long i=3;i*i<=a;++i)
    if(a%i==0) return 0;

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    unsigned long long a = 2;
    int p=63;
    vector<unsigned long long > v = {3,7,31,127,8191,131071,524287,2147483647,2305843009213693951};
   /* while(p)
    {
        a*=2;
        if(prime(a-1)) mp[a-1] = true;
        p--;
    } */
    while(n--)
    {
        unsigned long long b; cin >> b;
        if(binary_search(v.begin(),v.end(),b)) cout << "YES\n";
        else cout << "NO\n";
    }

}
