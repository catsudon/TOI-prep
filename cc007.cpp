#include<bits/stdc++.h>
using namespace std;

int main()
{
    string tomo,riru; cin >> tomo >> riru;
    for(int i=0;i<tomo.length();++i) tomo[i] = toupper(tomo[i]);
    for(int i=0;i<riru.length();++i) riru[i] = toupper(riru[i]);
    string ans = "";
    for(int i=0;i<tomo.length();++i)
    {
        int df = tomo[i] - riru[i];
        if(tomo[i] < riru[i]) df = ('Z'-riru[i]) + (tomo[i]-64);
      //  cerr << tomo[i] << " " << riru[i] << " " << df;
        if(df < 0 or df > 9)
        {
           cout << "R.I.P."; return 0;
        }
       // cerr << endl;
        ans.push_back(char(48+df));

    }
    cout << ans;

}
