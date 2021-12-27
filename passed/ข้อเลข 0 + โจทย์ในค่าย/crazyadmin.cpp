#include<bits/stdc++.h>
using namespace std;
int c,r;
int data_usage[109];
int main()
{
    cin >> c >> r;
    int avg=0;
    for(int i=0;i<r;++i)
    {
        cin >> data_usage[i];
        avg+=data_usage[i];
    }
    if(c==1) cout << avg;

    avg/=c;

}
