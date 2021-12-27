#include<bits/stdc++.h>
using namespace std;

int main()
{
    int w,h,n;
    cin >> w >> h >> n;
    vector<int> window(w+10,0);
    for(int i=0;i<n;++i)
    {
        int a,b; cin >> a >> b;
        for(int j=0;j<b;++j)
        {
            if(a+j >= w) break;
            else window[a+j]++;
        }

    }

    int tran=0,half=0;
    for(int i=0;i<w;++i)
    {
        if(window[i]==0) tran++;
        if(window[i]==1) half++;
    }

    cout << tran*h << " " << half*h;
}
