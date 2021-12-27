#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool debug=1;
ll atk[100009];
ll def[100009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int lim = (n-1)/2;
    for(int i=1;i<=n;++i)
    {
        cin >> atk[i];
        atk[i]+=atk[i-1];
    }
    for(int i=1;i<=n;++i)
    {
        cin >>  def[i];
        def[i]+=def[i-1];
    }
    for(int i=1;i<=n;++i)
    {
        int l = 0 , r = lim;
        ll power = atk[i]-atk[i-1];
        ll stat  = def[i]-def[i-1];
        int lastValid = 0;
        while(l<=r)
        {
            int mid = (l+r)/2; // ถล่มคนข้างๆ mid คน
            ll lower = 0; // ข้างซ้าย
        //    if(debug) mid=2;
            if(mid <= i-1) // ถล่มได้
            {
                lower+= def[i-1]-def[i-1-mid];
            }
            else
            {
                int left = mid;
                lower+=def[i-1];
                left -= i-1;
                lower+= def[n] - def[n-left];
           //     cerr << def[n] << " - " << def[n-left-1] << "     left = " << left << endl;
            }
            ll upper = 0;
            if(mid <= n-i)
            {
                upper+= def[i+mid] - def[i];
            }
            else
            {
                int left = mid;
                upper+= def[n]-def[i];
                left-=n-i;
                upper+= def[left];
            }
            ll sum = lower+upper;
     //       cerr << "at pos " << i << "  with mid = " << mid << "  lower = " << lower << " upper = " << upper << endl;
            if(sum > power) r=mid-1;
            else l=mid+1 , lastValid=mid;
        }
      //  cerr << "________________________________________\n";
      //  cerr << lastValid*2;
      //  cerr << "________________________________________\n";
      cout << lastValid*2 << ' ';
    }
}
