#include<bits/stdc++.h>
using namespace std;
int a[7];
int main()
{
    int n; cin >> n;
    int sum=0;
    for(int i=1;i<=5;++i)
    {
        cin >> a[i];
        sum+=a[i];
    }
    for(int i=1;i<=5;++i) cerr << a[i] << " ";
    cerr << endl;
    if(sum == n)
    {
        for(int i=1;i<=5;++i) cout << a[i] << " ";
    }
    else
    {
        for(int i=1;i<=5;++i)
        {
            if(sum-a[i] == n)
            {
                for(int j=1;j<=5;++j)
                {
                    j==i ? cout << 0 << " " : cout << a[j] << " ";
                }
                return 0;
            }
        }
        cout << -1;
    }
}
