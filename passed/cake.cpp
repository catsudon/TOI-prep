#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    float sum =0;
    for(int i=0;i<n;++i)
    {
        int a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;
        sum+=a;
        sum+=0.75*b;
        sum+=0.5*c;
        sum+=0.25*d;
        sum+=0.125*e;
    }
    int ss = sum;
    if(sum==ss) cout << sum;
    else cout << int(sum)+1;
}
