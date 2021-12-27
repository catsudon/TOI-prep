#include<bits/stdc++.h>
using namespace std;
string nesw = "NESW";
int main()
{
    int q; cin >> q;
    int x=0,y=0,d=1;
    while(q--)
    {
        string cmd;
        int n;
        cin >> cmd >> n;
      //  if(cmd == "FD") pass;
        if(cmd == "BW")d+=2;
        if(cmd == "RT")d++;
        if(cmd == "LT")d+=3;
        d%=4;

        if(d==0) x+=n;
        if(d==1) y+=n;
        if(d==2) x-=n;
        if(d==3) y-=n;

        if(x >= 50000 or x <= -50000 or y >= 50000 or y <= -50000)
        {
            cout << "DEAD"; return 0;
        }
        cerr << d << " " << y << " " << x << endl;
    }
    swap(x,y);
    cout << x << " " << y << endl;
    cout << nesw[d];
}
