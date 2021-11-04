#include<bits/stdc++.h>
using namespace std;
long long legend = 213;
int main()
{
    int n;
    cin >> n;
    char a[n+9];
    for(int i=1;i<=n;++i){ cin >> a[i];}
    long long sum = 0,coef=1;
    for(int i=1;i<=n;++i)
    {
        sum*=legend;
        sum+=a[i]-40;
        if(i!=n) coef*=legend;
    }

    long long xd=sum;
    int i=1;
    while(i)
    {
        sum-= (coef*(a[i]-40));
        sum*= legend;
        sum+= a[i]-40;

       // cout << sum << " " << xd << "\n";
        if(sum==xd) {
            cout<<i;break;
        }
        i++;
    }

}
