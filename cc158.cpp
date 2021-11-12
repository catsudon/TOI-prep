#include<bits/stdc++.h>
using namespace std;

set<int> sq;
int a,b;

bool isprime(int n)
{
    for(int i=2;i*i<=n;++i)
        if(n%i==0) return 0;
    return 1;
}

int main()
{
    cin >> a >> b;
 //   if(a>=4 and b<=4) sq.insert(4);
    for(int i=2;i*i<=b;++i)
    {
     //   cerr << isprime(i) << endl;
        if(isprime(i)) sq.insert(i*i);
    }


    bool ok=1;
    for(auto it : sq) if(it>=a and it<=b) {cout << it << " "; ok=0;}
    if(ok)cout << -1;
}
