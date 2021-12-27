#include<bits/stdc++.h>
using namespace std;
long long legend = 98765431 ;
int main()
{
    string s = "helloworld";
    string w = "oworl";
    long long coef=1;
    long long sum=0,ssum=0;
    for(int i=0;i<w.length();++i)
    {
        ssum*=legend;
        ssum+=s[i];
        sum*=legend;
        sum+=w[i];
        if(i>0)coef*=legend;
    }
    cout << coef << "\n";

    for(int i=0;i<s.length();++i)
    {
        ssum-=coef*s[i];
        ssum*=legend;
        ssum+=s[i+w.length()];
        cout << sum << " " << ssum << endl;
        if(ssum==sum) {cout << i ; return 0;}
    }
}
