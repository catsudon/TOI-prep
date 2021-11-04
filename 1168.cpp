#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    vector<long long> riru;

    long long c = 1;
    while(c <= 4294967296)
    {
        cerr << c;
        long long coef=10;
        while(c/coef)
        {

            if( (c/coef) > (c/(coef/10))%10 )
            {
                c+=(coef/10)*((c/coef) - (c/(coef/10))%10 + (coef/10));
                coef=1;
            }
            else if( (c/coef) == (c/(coef/10))%10 )
            {
                c+=(coef/10);
                coef=1;
            }
            coef*=10;
        }
        riru.emplace_back(c);
        cerr << ":" << c << endl;
        c++;
    }
  //  for(auto it : riru) cout << it << " ";
  while(q--)
  {
      int a; cin >> a;
      if(a >= riru.size()) cout << -1;
      else cout << riru[a];
      cout << endl;
  }


}
