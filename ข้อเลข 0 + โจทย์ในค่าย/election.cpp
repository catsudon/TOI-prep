#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n[5];
    for(int i=0;i<5;++i)
    {
        cin >> n[i];
    }
    for(int i=0;i<5;++i)
    {
        for(int j=0;j<n[i];++j)
        {
            int a;
            cin >> a;
            if(m[a]==NULL) m[a]=1;
            else m[a]++;
        }
    }
    int c=0;
    for(auto it : m)
    {
        if(it.second>=3) c++;
    }
    cout << c;
}
