#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t; cin >> t;
    while(t--)
    {
        int q; cin >> q;
        while(q--)
        {
            int a,b; cin >> a >> b;
            int mx = a-b-1;
            /// can always fulfill to a
            /// ex a=20 b=2
            /// 17
            /// op:2/1
            /// me:1/2 (always back to 20)
            int mn = a%(b+1); // ABSTRACT
            //  20
            //      |   k=2
            //  17  |
            //      |- op :2/1 (fulfill to k+1)
            //      |- me :1/2
            //  14  |
            //  .   |
            //  .   |
            //  .   |
            //  0
            if(mx <= 0) cout << -1 << endl;
            else if(mn==0) cout << b+1 << " " << mx << endl;
            else cout << mn << " " << mx << endl;
        }
    }
    return 0;
}
