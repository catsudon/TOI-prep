#include<bits/stdc++.h>
using namespace std;

int main()
{
  //  ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    while(q--)
    {
        int n,k; cin >> n >> k;
        int cnt = 0;
        int nn = n+1;
        while(true)
        {
            cnt++;
            if(nn<k*2) break;
            nn-=k;
        }
        cnt%=2;
        if(cnt) cout << "A" << endl;
        else cout << "B" << endl;
    }
}
