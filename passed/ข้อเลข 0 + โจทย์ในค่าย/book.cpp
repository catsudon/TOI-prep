#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> b;
    for(int i=0;i<n;++i)
    {
        int a;
        cin >> a;
        b.push_back(a);
    }
    int q;
    cin >> q;
    for(int i=0;i<q;++i)
    {
        int a;
        cin >> a;
        cout << b[a-1] << "\n";
        b.erase(b.begin()+a-1);
    }
}
