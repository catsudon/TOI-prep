#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,o,l=1,r=1e9,mx=0;
    cin >> n >> o;
    int room[o];
    for(int i=0;i<o;++i)
    {
        cin >> room[i];
        mx=max(mx,room[i]);
    }
    l=mx;
    while(l<r)
    {
        int mid = (l+r)/2;
        int wire = 1;
        int temp = 0;
        for(int i=0;i<o;++i)
        {
            temp += room[i];
       //     cerr << temp << " ";
            if(temp > mid) temp = room[i],wire++;
        }
        cerr << wire << " " << mid << endl;
        if(wire<=n) r = mid;
        else if(wire>n) l = mid+1;
    }
    cout << l;
}
