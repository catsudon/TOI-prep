#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int a = 5; // max upper part
    int b = 3;
    int c = 3;
    for(int i=4;i<n;++i) a+=2 , b++;

    for(int i=1;i<= n*2+1;++i) cout << "- "; cout << endl;
    while(b>=2)
    {
        for(int i=1;i<=b;++i) cout << "- ";
        for(int i=1;i<=c;++i) cout << "# ";
        for(int i=1;i<=b;++i) cout << "- ";
        cout << endl;
        c+=2;
        b--;
    }

    c-=4;
    b=1;
    while(c>0)
    {
        cout << "- ";
        for(int i=1;i<=b;++i) cout << "# ";
        cout << "- ";
        for(int i=1;i<=c;++i) cout << "# ";
        cout << "- ";
        for(int i=1;i<=b;++i) cout << "# ";
        cout << "- ";

        cout << endl;

        c-=2;
        b++;
    }
    cout << "- ";
    for(int i=1;i<=b;++i) cout << "# ";
    cout << "- ";
    for(int i=1;i<=b;++i) cout << "# ";
    cout << "- \n";
    a=1;
    for(int o=2;o<n;++o,--b,++a)
    {
        for(int i=1;i<=a;++i) cout << "- ";
        for(int i=1;i<=b;++i) cout << "# ";
        cout << "- ";
        for(int i=1;i<=b;++i) cout << "# ";
        for(int i=1;i<=a;++i) cout << "- ";
        cout << endl;
    }

    for(int i=1;i<= n*2+1;++i) cout << "- "; cout << endl;


}
