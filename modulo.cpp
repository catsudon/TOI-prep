#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n[10];
    set<int> s;
    for(int i=0;i<10;++i)
    {
        cin >> n[i];
        s.insert(n[i]%42);
    }

    cout << s.size();
}
