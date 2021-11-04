#include<bits/stdc++.h>
using namespace std;
int num[10009];
int temp[10009];

int ms(int l, int r)
{
    if(l>=r) return 0;
    int mid = (l+r)/2;
    cerr << l << " " << mid << " " << r << endl;
    ms(l,mid); ms(mid+1,r);

    int i=l,j=mid+1,pos=l;

    while(i<=l and j<=r)
    {
        if(num[i] < num[j]) temp[pos++] = num[i++];
        else temp[pos++] = num[j++];
    }
    while(i<=mid) temp[pos++] = num[i++];
    while(j<=r) temp[pos++] = num[j++];

    for(int i=l;i<=r;++i) {num[i] = temp[i];cerr << num[i] << " " ;} cerr << endl;


}

int main()
{
    int n; cin >> n;
    for(int i=1;i<=n;++i) cin >> num[i];
    ms(1,n);
    for(int i=1;i<=n;++i) cout << num[i] << " ";
}
