#include<bits/stdc++.h>
using namespace std;
int henshin[300];
int main()
{
    henshin['P']=0;
    henshin['-']=1;
    henshin['T']=2;
    henshin['X']=3;
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    for(int i=1;i<=q;++i)
    {
        string a; cin >> a;
        int mx = 0;
        for(auto it : a)
        {
            mx = max(mx,henshin[it]);
        }
        cout << "Case #" << i << ": ";

            mx == 0 ? cout << "Yes" :
            mx == 1 ? cout << "No - Wrong answer" :
            mx == 2 ? cout << "No - Time limit exceeded" :
            mx == 3 ? cout << "No - Runtime error":cerr <<"wtf";

        cout << endl;
    }
}
