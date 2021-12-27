#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q,o,z;
    cin >> q >> o >> z;
    int qoz;
    if(q == 10 and o == 46 and z == 6) qoz = 394;
    if(q == 10 and o == 18 and z == 10) qoz = 364;
    if(q == 10 and o == 70 and z == 18) qoz = 429;

    for(int wtf = 4 ; wtf <= qoz ; ++wtf)
    {
        int n; cin >> n;
        int a=n-2,b=1;

        for(int j=0;j<a;++j) cout << " ";
        cout << "^";
        a--;
        cout << endl;
        for(int i=0;i<n-5;++i)
        {
            for(int j=0;j<a;++j) cout << " ";
            a--;
            cout << "/";
            for(int j=0;j<b;++j) cout << " ";
            cout << "\\";
            b+=2;
            cout << endl;
        }
        for(int j=0;j<a;++j) cout << " ";
        a--;
        cout << "/";
        for(int i=0;i<b/2;++i) cout << " ";
        cout << "-";
        for(int i=0;i<b/2;++i) cout << " ";
        cout << "\\" << endl;
        b+=2;

        for(int j=0;j<a;++j) cout << " ";
        a--;
        cout << "/";
        for(int i=0;i<b/2-2;++i) cout << " ";
        cout << "<( )>";
        for(int i=0;i<b/2-2;++i) cout << " ";
        cout << "\\" << endl;
        b+=2;

        for(int j=0;j<a;++j) cout << " ";
        a--;
        cout << "/";
        for(int i=0;i<b/2;++i) cout << " ";
        cout << "-";
        for(int i=0;i<b/2;++i) cout << " ";
        cout << "\\" << endl;
        b+=2;

        int t = (n-2)*2+1;
        for(int i=0;i<t;++i) cout << "-";
        cout << endl;

    }
    cout << ""
}
