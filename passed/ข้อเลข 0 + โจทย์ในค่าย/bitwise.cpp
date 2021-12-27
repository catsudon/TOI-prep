#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    vector<bool> v[1<<n];
    for(int i=0;i<(1<<n);++i)
    {
        for(int j=0;j<4;++j){
            v[i].push_back(i&j);
            for(auto it : v[i]) cout << it;
            cout << "\n";
        }
    }
}
