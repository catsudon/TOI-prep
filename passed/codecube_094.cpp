#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; string s; cin >> n >> s;
    for(int i=1;i<s.length();++i)
    {
        if(s[i] == s[i-1] )
        {
            cout << "Wrong Answer";
            return 0;
        }
    }
    cout << "Accepted";
}
