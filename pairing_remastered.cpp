#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,z;
    cin >> x >> y >> z;
    int sum[z],room[x];
    map<int,bool> have;
    for(int i=0;i<x;++i) cin >> room[i];
    for(int i=0;i<y;++i)
    {
        int a; cin >> a;
        have[a] = true;
    }

    for(int i=0;i<z;++i) cin >> sum[i];
    int c=0;
    for(int i=0;i<z;++i)
    {
        for(int j=0;j<x;++j)
        {
            if(room[j]==-99 or sum[i]==-99) continue;
            if(have[sum[i]-room[j]]==true)
            {
                c++;
                have[sum[i]-room[j]] = false;
                room[j]=-99;
                sum[i]=-99;
            }
        }
    }
    cout << c;

}
