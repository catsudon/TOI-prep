#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;int k;
    cin >> s >> k;

    int x=0;
    int y=0;
    int n=0,ss=0,e=0,w=0;
    for(int i=0;i<s.length();++i)
    {
        if(s[i]=='N') y++,n++;
        if(s[i]=='E') x++,e++;
        if(s[i]=='S') y--,ss++;
        if(s[i]=='W') x--,w++;
    }

    int coef = abs(x) + abs(y) - k;
    cout << coef*2;

    if(x > 0) while(k>0 and x>0) x--,k--;
    if(y > 0) while(k>0 and y>0) y--,k--;
    if(x < 0) while(k>0 and x<0) x++,k--;
    if(y < 0) while(k>0 and y<0) y++,k--;

    int ans = abs(x) + abs(y) + k;
    cout << ans*2;

}
