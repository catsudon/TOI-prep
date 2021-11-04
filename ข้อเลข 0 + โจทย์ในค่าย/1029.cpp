#include<bits/stdc++.h>
using namespace std;
bool m[1000009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,q;
    cin >> n >> x >> q;
    for(int i=1;i<=x;++i)
    {
        int a,b;
        cin >> a >> b;
        for(int j=0;j<b;++j) m[a+j]==true? m[a+j]=false : m[a+j]=true;
    }
   // for(int i=1;i<=n;++i) cout << m[i] << " ";
   // cout << "\n";
    while(q--)
    {
        int a;
        cin >> a;
        int clonea = a;
        int c=1;
        bool b=m[a];
        while(true && a+c<n)
        {
            if(m[a+c]==b)
            {
                c++;
            }
            else break;
        }
        int x=c;
        c=1;
        while(true && a-c>0)
        {
            if(m[a-c]==b)
            {
                c++;
                x++;
            }
            else break;
        }
        cout << x << "\n";
    }
}
