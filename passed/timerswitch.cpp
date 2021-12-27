#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l; string s,z; cin >> l >> s;
    z = s+s;
    for(int i=1;i<=l;++i) if(l%i==0 and z.substr(i,l) == s)
    {
        cout << i;
        return 0;
    }
}
