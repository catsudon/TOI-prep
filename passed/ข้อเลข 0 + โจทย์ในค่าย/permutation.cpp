#include<bits/stdc++.h>
using namespace std;
int n;

void perm(int num,string s,vector<bool> vst)
{
    vst[num] = true;
    s.push_back(num+48);
    if(s.length()==n) cout << s << "\n";

    for(int i=1;i<=n;++i)
    {
        if(!vst[i]) perm(i,s,vst);
    }
}
int main()
{
    cin >> n;
    vector<bool> vst(n+1,false);
    for(int i=1;i<=n;++i)
    {
        string s;
        perm(i,s,vst);
    }
}
