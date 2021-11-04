#include <bits/stdc++.h>
using namespace std;
int num[100009];
int part (int l,int h)
{
    int pvt = num[h];
    int i=(l-1);

    for(int j=l;j<=h-1;j++)
    {
        if(num[j]<pvt)
        {
            int temp = num[i];
            num[i] = num[j];
            num[j] = temp;
        }
    }
    int temp = num[i+1];
    num[i+1] = num[h];
    num[h]   = temp;
    return (i+1);
}


int qs(int l,int h)
{
    if(l>=h) return 0;

    int p = part(l,h);
    qs(l,p-1);
    qs(p+1,h);

}

int main()
{
    int n; cin >> n;
    for(int i=0;i<n;++i) cin >> num[i];
    int l=0,h=n-1;
    qs(l,h);

    for(int i=0;i<n;++i) cout << num[i] << " ";
}
