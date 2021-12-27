#include<bits/stdc++.h>
using namespace std;
/// idea : bitflip over 0 only

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int lim = (1 << n);
 //   cerr << lim;

    for(int i=0;i<lim;++i)
    {
        // make binary
     //   cerr << i << " " ;
        vector<int> v;
        vector<int> bin(n);
        int num = i;
        while(num)
        {
            v.push_back(num%2);
            num/=2;
        }
        while(v.size()!=n) v.push_back(0);
        for(int i=0;i<n;++i) bin[i] = v[n-i-1];
  //      for(auto it : bin) cerr << it ; cerr << endl;

        for(int p=n-1;p>=0;--p)
        {
            if(bin[p]==1) continue;
            for(auto it : bin) cout << it ; cout << " ";
            bin[p] = 1;
            for(auto it : bin) cout << it ; cout << endl;
            bin[p] = 0;
        }
    }
}
