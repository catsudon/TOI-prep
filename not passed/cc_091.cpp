#include<bits/stdc++.h>
using namespace std;
int n;
string s,t;
string ans;
bool forsureNO = false;
bool ok = 0;
string BWG = "BWG";

int dfs(int i)
{
    if(ok or forsureNO) return 0;
    if(i==n) ans = s,ok=true;

   // cerr << i << " " << s << endl;
    if(s[i] == 'X')
    for(auto it : BWG)
    {
        if(i>0 and it == s[i-1]) continue;
        if(i!=n-1 and it == s[i+1]) continue;
        s[i] = it;
        dfs(i+1);
        s[i] = t[i];
    }
    else
    {
        if(i>0 and s[i] == s[i-1]) forsureNO = 1;
        else if(i!=n-1 and s[i] == s[i+1]) forsureNO = 1;
        else dfs(i+1);
    }
}

int main()
{
    cin >> n >> s; t=s;
    dfs(0);
    if(forsureNO) ok=0;
    ok ? cout << ans : cout << "No Answer";
}
