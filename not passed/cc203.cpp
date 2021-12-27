#include<bits/stdc++.h>
using namespace std;
int s[1009];
int coef=0,llenn;

int sol(int idx)
{
    if(s[idx] == 2) return 1;
    if(s[idx] == 1)
    {
        if(idx == llenn) return 1;
        ///else return 1/0;
        else
        {
            int temp = sol(idx+1);
            cerr << temp << " ";
   //         if() ...
     //       if() ...
       //     if() ...
            return 0;
        }
    }
    if(s[idx] == 0) return 0;
    if(s[idx] ==-1)
    {
        if(idx == llenn) return -9999999;
        else coef+=sol(idx+1);
    }

}

int main()
{
    string a; cin >> a; llenn = a.length();
    int p=1;
    for(auto it : a)
    {
        if(it == '?') s[p] = -1;
        else s[p] = it-48;
        p++;
    }

    for(int i=1;i<=llenn;++i)
    {
        if(s[i]!=-1) continue;
        coef = 0;
        int l = s[i-1];
        int r = sol(i);
        cerr << l << " " << r << endl;
        s[i] = l+r;
      //  if() ...
      //  if() ...
    }
    int l = 0;
    for(int i=1;i<=llenn;++i)
    {
        if(i==1) {cout << 'x';continue;}

        if(s[i-1] == 2 or i==2) cout << '-';
        else if(s[i-1] == 1)


        if(i==llenn) cput << 'x';
    }
}
