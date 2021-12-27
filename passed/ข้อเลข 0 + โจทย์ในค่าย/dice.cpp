#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin >> n;
    string s[n];
    for(int i=0;i<n;++i) cin >> s[i];
    for(int i=0;i<n;++i)
    {

        int d[6] = {1,2,3,5,4,6};
        for(int j=0;j<s[i].length();++j)
        {
            int t0 = d[0],t1 = d[1],t2 = d[2],t3 = d[3],t4 = d[4],t5 = d[5];
            if(s[i][j]=='F')
            {
                d[0]=t3;
                d[1]=t0;
                d[3]=t5;
                d[5]=t1;
            }
            if(s[i][j]=='B')
            {
                d[0]=t1;
                d[1]=t5;
                d[3]=t0;
                d[5]=t3;
            }
            if(s[i][j]=='L')
            {
                d[0]=t4;
                d[2]=t0;
                d[4]=t5;
                d[5]=t2;
            }
            if(s[i][j]=='R')
            {
                d[0]=t2;
                d[2]=t5;
                d[4]=t0;
                d[5]=t4;
            }
            if(s[i][j]=='C')
            {
                d[1]=t4;
                d[2]=t1;
                d[3]=t2;
                d[4]=t3;
            }
            if(s[i][j]=='D')
            {
                d[1]=t2;
                d[2]=t3;
                d[3]=t4;
                d[4]=t1;
            }
        }
        cout << d[1] << " ";
    }
}
