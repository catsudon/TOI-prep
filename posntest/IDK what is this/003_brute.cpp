#include<bits/stdc++.h>
using namespace std;
vector<int> qs(100009,0);
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i=2;i<=n;++i)
    {
        cin >> qs[i];
        qs[i]+=qs[i-1];
        //cerr << " " << qs[i];
    }//cerr << endl;

    while(q--)
    {
        int op,ed; cin >> op >> ed;
        int mn = INT_MAX;
        for(int i=op;i<=ed;++i)
        {
            mn = min(mn,max(qs[i]-qs[op],qs[ed]-qs[i]));
        }
        cout << mn << endl;

    }
}
