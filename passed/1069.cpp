#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    stack<char> s[2];
    bool toggle = 0; // 0 = s[0] ;   1 = s[1]
    for(int i=0;i<n;++i)
    {
        char a; cin >> a;
        s[0].push(a);
    }
    bool chg = true;
    int t=0;
    while(chg )
    {
        t++;
        chg = false;
        bool untoggle = !toggle;
        while(s[toggle].size())
        {
            char F = s[toggle].top();
            s[toggle].pop();
            if(s[toggle].size() and F == s[toggle].top())
            {s[toggle].pop(); chg = true; continue;}
            s[untoggle].push(F);
        }

        while(s[1].size())
        {
            s[0].push(s[1].top());
            s[1].pop();
        }
    }

    cout << s[0].size() << endl;
    if(s[0].empty()){cout << "empty"; return 0;}
    vector<char> v;
    while(s[0].size())
    {
        v.push_back(s[0].top());
        s[0].pop();
    }
    for(int i=0;i<v.size();++i) cout << v[i];


}
