//matrix chain
#include<bits/stdc++.h>
using namespace std;

int segitiga(int a,int b)
{
    if(a==0)
    {
        if(b==0) return 2;
        if(b==1) return 1;
        if(b==2) return 0;
    }
    if(a==1)
        {
        if(b==0) return 2;
        if(b==1) return 1;
        if(b==2) return 1;
    }
    if(a==2)
    {
        if(b==0) return 1;
        if(b==1) return 2;
        if(b==2) return 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int r=0;r<20;++r)
    {
        int llenn; cin >> llenn;
        string str; cin >> str;
        int ans=str[0]-48;
        for(int i=1;i<str.length();++i)
        {
            ans = segitiga(ans,str[i]-48);
        }
        ans==0?cout << "yes\n":cout << "no\n";
    }
}
