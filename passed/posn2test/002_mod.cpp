/*
TASK: LoftyPair.cpp
LANG: C++
AUTHOR: Sathana Laolugsanalerd
ID: 63022
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll mx = -1;
int c=0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
//    for(int i=0;i<n;++i) cin >> v[i];

    ll sum=0;
    for(int i=0;i<n;++i)
    {
        for(int j=i+2;j<n;++j)
        {
            for(int k=i+1;k<j;++k)
            {
              //  if(v[k-1] > v[i]) break;
                bool ok = true;
            //    ll sum = v[i]+v[j];
              //  ll mae = v[i];
                for(int l=i+1;l<=k and ok;++l)
                {
                    sum++; cerr << sum << endl;
                }
           //     mae=v[k];
                for(int r=k+1;r<=j and ok;++r)
                {
                    sum++;
                }
          //      if(!ok ) continue;
            //    mx = max(mx,sum);
        //        c++;
      //          if(ok) break;
            }
        }
    }

    cout << c << endl << mx;
    cout << endl << endl << sum;


}

