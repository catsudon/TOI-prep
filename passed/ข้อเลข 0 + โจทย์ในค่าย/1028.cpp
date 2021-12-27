#include<bits/stdc++.h>
using namespace std;
map<char,int> m;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(true)
    {
        char cmd;
        cin >> cmd;
        if(cmd=='!') {cout << "!"; return 0;}
        if(cmd=='=')
        {
            char a;
            int n;
            cin >> a >> n;
            m[a] = n;
        }
        else if(cmd=='#')
        {
            char a;
            cin >> a;
            cout << m[a] << "\n";
        }
        else
        {
            char a,b;
            cin >> a >> b;
            if(cmd=='+') m[a] += m[b];
            if(cmd=='-') m[a] -= m[b];
            if(cmd=='*') m[a] *= m[b];
            if(cmd=='/') m[a] /= m[b];
        }
    }
}
