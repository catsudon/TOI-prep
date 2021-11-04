#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--)
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
}
