#include<bits/stdc++.h>
using namespace std;
int alp[130];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(true)
    {
        char cmd; cin >> cmd;
        if(cmd == '!') {cout << "!"; return 0;}
        if(cmd == '+')
        {
            char a,b; cin >> a >> b;
            alp[a]+=alp[b];
          //  cout << alp[a];
        }
        if(cmd == '-')
        {
            char a,b; cin >> a >> b;
            alp[a]-=alp[b];
          //  cout << alp[a];
        }
        if(cmd == '*')
            {
            char a,b; cin >> a >> b;
            alp[a]*=alp[b];
           // cout << alp[a];
        }
        if(cmd == '/')
        {
            char a,b; cin >> a >> b;
            alp[a]/=alp[b];
         //   cout << alp[a];
        }
        if(cmd == '#')
        {
            char v; cin >> v;
            cout << alp[v] << endl;
        }
        if(cmd == '=')
        {
            char v; int val;
            cin >> v >> val;
            alp[v] = val;
        }

        //cout << endl;
    }
}
