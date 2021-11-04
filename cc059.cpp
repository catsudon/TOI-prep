#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m; cin >> n >> m;
    int c=1;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cout << char(64+c++);
            c%=27;
            if(c==0) c++;
        }
        cout << endl;
    }
}
