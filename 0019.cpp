#include<bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int main()
{
    int n,mn = INF;
    cin >> n;
    int s[n],b[n];
    for(int i=0;i<n;++i) cin >> s[i] >> b[i];
    for(int i=1;i<=(1<<(n))-1;++i)
    {
        int B=0,S=1;
        deque<int> bin;
        int ii = i;
        while(ii)
        {
            bin.push_front(ii%2);
            ii/=2;
        }
        for(auto it : bin) cerr << it;
        cerr << "   ";
        while(bin.size()!=n) bin.push_front(0);
        int p=0;
        for(auto it : bin)
        {
            cerr << it;
            if(it)
            {
                B+=b[p];
                S*=s[p];
            }
            p++;
        }
        cerr << " " << B << " " << S << endl;
        mn = min(mn,abs(B-S));
    }
    cout << mn;

}
