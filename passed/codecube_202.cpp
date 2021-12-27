#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int day[n];
    cin >> day[0];
    int sum=0;
    for(int i=1;i<n;++i)
    {
        cin >> day[i];
        if(day[i]-day[i-1]>0) sum+=day[i]-day[i-1];
    }
    cout << sum;
}
