#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> s;
    for(int i=0;i*20<=n;++i)
    {
        for(int j=0;i*20+j<=n;j+=3)
        {
            if(i*20+j>=6 && i*20+j!=23 && i*20+j!=43) s.insert(i*20+j);
        }
    }
    for(auto it : s) cout << it << endl;
    if(s.empty()) cout<< "no";
}
