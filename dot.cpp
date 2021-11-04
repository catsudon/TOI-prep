#include<bits/stdc++.h>
using namespace std;
bool have[1009][1009];

int main()
{
    int n,sum=0; cin >> n;
    for(int i=0;i<n;++i)
    {
       int a,b;
       cin >> a >> b;
       if(!have[a][b])
       {
           sum++;
           have[a][b] = true;
       }
    }


    cout << sum;

}
