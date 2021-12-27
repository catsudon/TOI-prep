#include<bits/stdc++.h>
using namespace std;
int dp[1000009];
int teleport[1000009];
int gate[1000009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    while(q--)
    {
        ios_base::sync_with_stdio(0);
        string bik,smol;
        cin >> bik >> smol;             int llenn = smol.length();
        bik  = ' ' + bik + ' ';
        smol = ' ' + smol;
        for(int i=0;i<=bik.length();++i) dp[i] = i+1 , teleport[i] = 1 , gate[i] = i;
        for(int i=2;i<=bik.length();++i)
        {
            if(bik[i] == bik[teleport[i-1]]) teleport[i] = teleport[i-1]+1;
            cerr << teleport[i] << ' ';
        }cerr << endl;
        int p=1;
        bool normal  = 1;
        for(int i=1;i<bik.length()-1;normal ? i=dp[i] : i=i)
        {
            normal=1;

            if(bik[i] == smol[p]) // match
            {
                if(p++ == llenn)
                {                                                     //            i-len      fill
                    p=1;                                              //               v |/////////////|
                    for(int j=i-llenn+1;j<=i;++j) gate[j] = i-llenn;  // C o d e C o d e C o d e C u b e
                    i=dp[max(1,i-llenn-(llenn-1))]; normal=0;
                }
            }
            else
            { // failed
                p = gate[dp[teleport[i]]];
                cerr << "teleported to " << p  << " problem at i= " << i << endl;
            }
        }
        for(int i=1;i<bik.length();++i) cerr << dp[i] << ' ';
        cerr << endl;
        for(int i=dp[0];i<bik.length();i=dp[i])
            cout << bik[i];
        cout << endl;
    }
}
