#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int a,k,b;

int start(int F,int S,char wl,vector<char> v)
{
    if(wl=='W') F++;
    if(wl=='L') S++;
    v.push_back(wl);
    if(F==k || S==k)
    {
        for(auto it:v) cout << it << " ";
        cout << "\n";
        return 0;
    }
    start(F,S,'W',v);
    start(F,S,'L',v);
}

int main()
{
    cin >> k >> a >> b;
    vector<char> v;
    start(a,b,'W',v);
    start(a,b,'L',v);
}
