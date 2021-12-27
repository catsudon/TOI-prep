#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int q; cin >> q;
    int p=1;
    while(q--)
    {
        int a,b; cin >> a >> b;
        int fulltime = a;
        int want = b;
        int i = want%20;
        int ans = min(a,b)/20;
        ans++;
        if(b>a and i > fulltime%20 ) ans--;  // try 41 and 42
                                             // you'll see that
                                             // 2  + 40 = 42
                                             // 22 + 20 = 42
                                             // but 42 + 0 cannot be used because m is 41
                                             // so in this case you have to -1
        cout << "Case #" << p << ": " << ans << endl;
        p++;
    }
}
