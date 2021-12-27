#include<bits/stdc++.h>
using namespace std;

long long power(int a,int n)
{
    if(n==1) return a;
    if(n%2==0) {
        int temp = power(a,n/2);
        temp*=temp;
        return temp;
    }
    if(n%2==1)
    {
        int temp = power(a,(n-1)/2);
        temp=temp*temp *a;
        return temp;
    }
}

int main()
{
    int a,n;
    cin >> a >> n;
    chrono::steady_clock::time_point _start(chrono::steady_clock::now());

    long long ans=1;
    for(int i=0;i<n;++i) ans*=a;
    cout << ans << " ";

    chrono::steady_clock::time_point _end(chrono::steady_clock::now());
    cout << chrono::duration_cast<chrono::duration<double>>( _end - _start).count();

    chrono::steady_clock::time_point _start(chrono::steady_clock::now());

    cout << endl << power(a,n) << " ";

    chrono::steady_clock::time_point _end(chrono::steady_clock::now());
    cout << chrono::duration_cast<chrono::duration<double>>( _end - _start).count();

}
