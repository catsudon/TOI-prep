#include<bits/stdc++.h>
using namespace std;
int a[100];
int mn = INT_MAX,rr=-1;
int main()
{
    int n; cin >> n;
    for(int i=1;i<=9;++i)
    {
        cin >> a[i];
        if(a[i] <= mn) rr=i,mn=a[i];
    }

    int mxPz = n/mn;
    int chg = n%mn;
    for(int r=mxPz;r>=1;--r)
    {
        for(int i=9;i>=rr;--i)
        {
            if(i==rr) cout << rr;
            else if(a[i]-a[rr] <= chg)
            {
                chg-=a[i]-a[rr];
                cout << i;
                break;
            }
        }
    }


}
