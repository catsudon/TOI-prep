#include<bits/stdc++.h>
using namespace std;
bool vst[500009];
int main()
{
    int tomo,riru,banzai=0;
    cin >> tomo >> riru;
    for(int i=2;i<=tomo;++i)
    {
        if(vst[i]) continue;
        else
        {
            banzai++;
            for(int j=i;j<=tomo;j+=i)
            {
                vst[j] = true;
            }
        }
    }

    cout << max(0,banzai-riru);
}
