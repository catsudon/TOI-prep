#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n;  cin >> n; int p1=n,p2=n; n+=n;

    int streak = 0;
    while(n--)
    {
        int a; cin >> a;
        if(a%2==0 and streak <= 0 ) streak = 1;
        else if (a%2==1 and streak >= 0) streak=-1;

        else if(a%2==0) streak++;
        else streak--;

        if( a%2==0 and streak >=3) p2-=3;
        else if(a%2==0) p2--;

        if( a%2==1 and streak <=-3) p1-=3;
        else if(a%2==1) p1--;

        if(p1 <= 0 ) cout << 1 << endl << a;
        if(p2 <= 0 ) cout << 0 << endl << a;

        if(p1<=0 or p2<=0) return 0;
    }

}
