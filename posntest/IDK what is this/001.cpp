#include<bits/stdc++.h>
using namespace std;
int want[7];
int havin[7];
int main()
{
    int n; string s; cin >> n >> s;
    deque<char> dq;
    for(int i=0;i<7;++i) cin >> want[i];
    for(int i=0;i<n;++i)
    {
        havin[s[i]-'a']++;
        dq.push_back(s[i]);
    }
    int chg=0;

    while(!dq.empty() and havin[dq.back()-'a'] > want[dq.back()-'a'])
    {
        havin[dq.back()-'a']--;
        dq.pop_back();
    }

    while(!dq.empty() and havin[dq.front()-'a'] > want[dq.front()-'a'])
    {
        havin[dq.front()-'a']--;
        dq.pop_front();
    }
    for(auto it : dq)
    {
        if(havin[it-'a'] > want[it-'a'])
        {
            chg++;
            havin[it-'a']--;
        }
    }

    cout << chg;

}
