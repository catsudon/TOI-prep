#include<bits/stdc++.h>
using namespace std;
char tabetai[3] = {'(','[','{'};
char hungry[400];
int main()
{
    hungry[')'] = '(';
    hungry['}'] = '{';
    hungry[']'] = '[';
    int q; cin >> q;
    while(q--)
    {
        string katsu; cin >> katsu; stack<char> don;
        bool ok = 1;
        for(auto it : katsu)
        {
            bool naaaa = 0;
            for(int i=0;i<3;++i) if(it==tabetai[i]) naaaa = 1;
            if(naaaa)
            {
                don.push(it);
                continue;
            }
            else
            {
                if(don.size())
                {
                    char tabetaiii = don.top(); don.pop();
                 //   cerr << tabetaiii << " " << it << endl;
                    if(tabetaiii == hungry[it]) continue;
                    else {ok=0;break;}
                }
                else {ok = 0; break;}
            }
        }
        if(don.size() or !ok) cout << "no\n";
        else cout << "yes\n";
    }
}
