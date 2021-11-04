#include<bits/stdc++.h>
using namespace std;
vector<int> prime;

int main()
{
    int a,b,c,d; cin >> a >> b >> c  >> d;
    int mx = max(max(a,b),max(c,d));
    prime.emplace_back(2);
    for(int i=3;i<=mx;i+=2)
    {
        bool isprime = 1;
        for(int j=3;j<=i/2;++j)
        {
            if(i%j==0) {isprime=0; break;}
        }
        if(isprime) prime.emplace_back(i);
    }

    for(auto it : prime) cout << it << endl;
}
