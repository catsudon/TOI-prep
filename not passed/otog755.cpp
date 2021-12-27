#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    stack<pair<char,int> > s;
    while(q--)
    {
        char AA; char BB;
        cin >> AA >> BB;
        if(BB >= '0' and BB <= '9') BB-='0';
        s.push({AA,BB});
    }
    string ans = "";
    while(s.size())
    {
        char cmd = s.top().first;
        if(cmd == 'U')
        {
            int t = s.top().second;
            s.pop();
            while(t and s.size())
            {
             //   cerr << "popped " << (char)s.top().first << " " << s.top().second << endl;
                s.pop(); t--;
            }
        }
        else
        {
           ans.push_back((char)s.top().second);
         //   cerr << (char)s.top().second << ' ';
            s.pop();

        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans;
}
