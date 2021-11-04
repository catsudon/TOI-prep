#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int A,B,C; cin >>  A >> B >> C;
    for(int a=1;a<=100;++a)
    {
        if(A%a)continue;
        for(int b=-100;b<=100;++b)
        {
            if(b==0 or C%b) continue;
            int c=A/a;
            int d=C/b;
            if(a*d+c*b==B){cout << a << " " << b << " " << c << " " << d;return 0;}
        }
    }
    cout << "No Solution";
}
